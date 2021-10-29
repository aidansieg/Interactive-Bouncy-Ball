//
// Created by Aidan Siegel on 5/12/21.
//
#include "circle.h"
#include "graphics.h"
#include <iostream>
using namespace std;

double Circle::getRadius() const {
    return radius;
}

double Circle::getBallX() const {
    return ballX;
}

double Circle::getBallXmax() const {
    return ballXmax;
}

double Circle::getBallXmin() const {
    return ballXmin;
}

double Circle::getBallY() const {
    return ballY;
}

double Circle::getBallYmax() const {
    return ballYmax;
}

double Circle::getBallYmin() const {
    return ballYmin;
}

double Circle::getSpeedX() const {
    return speedX;
}

double Circle::getSpeedY() const {
    return speedY;
}

void Circle::setBallX(double posX) {
    ballX = posX;
}

void Circle::setBallXmax(double maxX) {
    ballXmax = maxX;
}

void Circle::setBallXmin(double minX) {
    ballXmin = minX;
}

void Circle::setBallY(double posY) {
    ballY = posY;
}

void Circle::setBallYmax(double maxY) {
    ballYmax = maxY;
}

void Circle::setBallYmin(double minY) {
    ballYmin = minY;
}

void Circle::setSpeedX(double xS) {
    speedX = xS;
}

void Circle::setSpeedY(double yS) {
    speedY = yS;
}

void Circle::setRadius(double r) {
    if (r < 0) {
        r = 0;
    }
    radius = r;
}

void Circle::size(bool size) {
    if (size) {
        radius += 0.02;
    }
    else {
        radius -= 0.02;
    }
}

void Circle::speed(bool size) {
    if (size) {
        speedX += 0.01;
    }
    else {
        speedX -= 0.01;
    }
}
