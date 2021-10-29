//
// Created by Aidan Siegel on 5/12/21.
//

#ifndef CONFETTIFY_BUTTON_CIRCLE_H
#define CONFETTIFY_BUTTON_CIRCLE_H
#include <math.h> // This allows you to use sqrt and pow functions
#include <string>

const double PI = 3.14159265358979323846;

class Circle{
    struct color {
        double red;
        double green;
        double blue;
        double alpha;
    };

private:
    double radius;
    double ballX;
    double ballXmax;
    double ballXmin;
    double ballY;
    double ballYmax;
    double ballYmin;
    double speedX;
    double speedY;
public:
    /* Destructor */
    virtual ~Circle() = default;

    /* Getters */
    double getRadius() const;
    double getBallX() const;
    double getBallXmax() const;
    double getBallXmin() const;
    double getBallY() const;
    double getBallYmax() const;
    double getBallYmin() const;
    double getSpeedX() const;
    double getSpeedY() const;

    /* Setters */
    void setRadius(double r);
    void setBallX(double posX);
    void setBallXmax(double maxX);
    void setBallXmin(double minX);
    void setBallY(double posY);
    void setBallYmax(double maxY);
    void setBallYmin(double minY);
    void setSpeedX(double xS);
    void setSpeedY(double yS);

    void size(bool size);

    void speed(bool size);
};
#endif //CONFETTIFY_BUTTON_CIRCLE_H
