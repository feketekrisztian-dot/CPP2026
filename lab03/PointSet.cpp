//
// Created by fkris on 9/28/2026.
//

#include  "PointSet.h"
#include <iostream>
#include <algorithm>
#include <random>

PointSet::PointSet( int n ) {
    this->n=n;
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd()); // Mersenne Twister algorithm to generate random numbers
    uniform_int_distribution<int> dist(0, M);
    while (this->points.size()<n) {
        int x = dist(mt);
        int y = dist(mt);

        Point a(x,y);

        bool talalt=false;
        for (auto& p : this->points) {
            if (p.getX()==x && p.getY()==y) {
                talalt=true;
                break;
            }
        }
        if (!talalt)
            points.push_back(a);
    }

    this->computeDistances();
}


void PointSet::computeDistances() {
    for (int i=0; i<this->points.size(); i++)
        for (int j=i+1;j<this->points.size();j++) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
}


double PointSet::maxDistance() const {
    return *max_element(distances.begin(),distances.end());
}
double PointSet::minDistance() const {
    return *min_element(distances.begin(),distances.end());
}
int PointSet::numDistances() const {
    return distances.size();
}
void PointSet::printPoints() const {
    for (auto &p:this->points)
        cout<<p.getX()<<' '<<p.getY()<<endl;
}
void PointSet::printDistances() const {
    for (auto &p:this->distances)
        cout<<p<<endl;
}
bool cmpX (Point i,Point j) { return (i.getX()<j.getX()); }

void PointSet::sortPointsX() {
    sort(points.begin(),points.end(),cmpX);
}

bool cmpY (Point i,Point j) { return (i.getY()<j.getY()); }
void PointSet::sortPointsY() {
    sort(points.begin(),points.end(),cmpY);
}
bool cmpDis(double i,double j) { return (i<j); }
void PointSet::sortDistances() {
    sort(distances.begin(),distances.end(),cmpDis);
}

int PointSet::numDistinctDistances() {
    //vector <double> distences = this->distances;
    sort(distances.begin(),distances.end());
    auto mid=unique(distances.begin(),distances.end());
    return mid- distances.begin();
}

