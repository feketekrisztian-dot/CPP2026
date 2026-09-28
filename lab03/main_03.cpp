
#include <iomanip>
#include <vector>
#include <iostream>

#include "PointSet.h"
using namespace std;

vector<int> v;

int main() {
  /*  for( int i=0; i<10; ++i ){
        v.push_back( i * 10 );
    }
    for(int i=0; i<v.size(); ++i ){
        cout<<v[ i ]<<" ";
    }
    cout<<endl;
*/

    PointSet ps1(7);
    ps1.printPoints();
    ps1.sortPointsX();
    ps1.printPoints();
/*
    PointSet* ps=new PointSet(5);

    ps->printPoints();
    ps->sortPointsX();
    ps->printPoints();

    delete ps;*/

    int n = 2;
    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"
    <<endl;
    cout<< fixed;
    for( int i= 0; i<12; ++i ){
        PointSet pSet( n );
        cout<<setw(6)<<n<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
        cout<<setw(10) << pSet.numDistances()<<" ";
        cout<<setw(16) << pSet.numDistinctDistances()<<endl;
        n = n << 1;
    }

}
