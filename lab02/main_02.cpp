#include <iostream>
#include "Point.h"
#include "util.h"
#include <fstream>
using namespace std;
int main(int argc, char** argv) {
    /*Point p1(2,3);
    Point p3(2);
    Point p4;
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    delete pp1;
    delete pp2;*/
    Point   p1(1, 1);
    Point p2(0, 0);
    cout<<distance(p1,p2)<<endl<<endl;

    Point   s1(0,0);
    Point   s2(4, 4);
    Point   s3(0, 4);
    Point   s4(4, 0);
    cout<<isSquare(s1,s2,s3,s4)<<endl;

    testIsSquare("be.txt");


    return 0;
}