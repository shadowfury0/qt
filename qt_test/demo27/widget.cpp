#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    audioRecorder = new QAudioRecorder;
    QStringList inputs = audioRecorder->audioInputs();
    ui->comboBox->addItems(inputs);
    connect(audioRecorder,&QAudioRecorder::durationChanged,this,&Widget::udateProgress);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName();
    ui->lineEdit->setText(fileName);
}


void Widget::on_pushButton_2_clicked()
{
    audioRecorder->setAudioInput(ui->comboBox->currentText());
    audioRecorder->setOutputLocation(QUrl::fromLocalFile(ui->lineEdit->text()));
    audioRecorder->record();
}

void Widget::on_pushButton_3_clicked()
{
    audioRecorder->stop();
}

void Widget::udateProgress(qint64 duration)
{
    if(audioRecorder->error()!=QMediaRecorder::NoError || duration <1000)
        return;
    setWindowTitle(tr("Recorded %1 sec").arg(duration/1000));
}
