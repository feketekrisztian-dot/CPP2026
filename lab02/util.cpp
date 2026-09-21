//
// Created by fkris on 9/21/2026.
//

#include "util.h"

#include <cmath>
#include <iostream>
#include <fstream>

#include "Point.h"

double distance(const Point& a, const Point& b) {
    return sqrt((a.getX()-b.getX())*(a.getX()-b.getX())+(a.getY()-b.getY())*(a.getY()-b.getY()));
}
int compare(const void* a, const void* b)
{
    const int* x = (int*) a;
    const int* y = (int*) b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

    return 0;
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point&d) {
    double t[7];
    t[0]=distance(a,b);
    t[1]=distance(a,c);
    t[2]=distance(a,d);
    t[3]=distance(b,c);
    t[4]=distance(b,d);
    t[5]=distance(c,d);

    qsort(t,6,sizeof(t[0]),compare);
    if (t[0]==t[1] and t[0]==t[2] and t[0]==t[3] and t[0]<t[4] and t[4]==t[5])
        return true;
    return false;
}
void testIsSquare(const char * filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cout << "A fajl nem nyithato meg "<<std::endl;
        return;
    }

    int t[8];
    while (in>>t[0]>>t[1]>>t[2]>>t[3]>>t[4]>>t[5]>>t[6]>>t[7]) {
        std::cout<<t[0]<<t[1]<<t[2]<<t[3]<<t[4]<<t[5]<<t[6]<<t[7]<<std::endl;
    }


}

