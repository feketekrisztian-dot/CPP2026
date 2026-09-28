#include "Point.h"

#include <cmath>
#include <iostream>
using namespace std;
Point::Point(int x, int y) {
    if (x >= 0 && x <= M && y >= 0 && y <= M) {
        this->x = x;
        this->y = y;
    }
    else {
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return this->x;
}
int Point::getY() const {
    return this->y;
}
double Point::distanceTo(const Point& point)const{
    return sqrt((this->getX()-point.getX())*(this->getX()-point.getX())+(this->getY()-point.getY())*(this->getY()-point.getY()));
}
