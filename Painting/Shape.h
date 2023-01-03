#ifndef SHAPE_H
#define SHAPE_H
class Shape{
public:
    enum type{
      normal_pen = 0,
      two_d = 1,
      sticker = 2,
      edit = 3,
    };
    //Pen
    enum pen{
        //最初始的画笔
      n_pen = 0,
      pencil =2,
      rubber = 4,
    };
    enum penStyle{
        //penStyle
        solid =  0,
        dash  =  1,
        dot   =  2,
        dashdot= 3,
    dashdotdot = 4,
        custom = 5,
        //capStyle
        square = 6,
        flat   = 7,
        roundcap  = 8,
        //joinStyle
        bevel  = 9,
        miter  = 10,
        roundjoin  = 11,
    };
    //2D
    enum td{
        Line = 0,
        UpArc = 1,
        DownArc = 2,
        Ellipse = 5,
        Rectangle = 6,
        RoundRectangle = 7,
        Chord = 8,
        Triangle = 9,
        Pentagon = 10,
        Hexagon = 11,
        Heptagon = 12,
        Diamond = 13,
        Arrow = 14,
    };
    enum color{
        white = 0,
        black = 1,
        red = 2,
        darkRed = 3,
        green =4,
        darkGreen =5,
        blue = 6,
        darkBlue = 7,
        cyan = 8,
        darkCyan = 9,
        magenta = 10,
        darkMagenta =11,
        yellow = 12,
        darkYellow = 13,
        gray = 14,
        darkGray = 15,
    };
    enum editMode{
        select = 0,
        draw = 1,
    };
};

#endif // SHAPE_H
