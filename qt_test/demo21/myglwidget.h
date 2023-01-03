#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
class QOpenGLShaderProgram;
class MyOpenGLWidget : public QOpenGLWidget,protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit MyOpenGLWidget(QWidget * parent = 0);
    void resizeGL(int, int);
    void paintGL();
protected:
    void initializeGL() ;
private:
    QOpenGLShaderProgram * program;
};

#endif // MYOPENGLWIDGET_H
