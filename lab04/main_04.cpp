#include <iostream>

#include "Polynomial.h"
using namespace std;
int main() {

    double x[] = {1, 2, 4 };
    Polynomial a=Polynomial(2,x);
    cout<<a.evaluate(2)<<endl;
    cout<<a.derivative()<<endl;
    cout<<a[2]<<endl;
    cout<<-a<<endl;
    double y[]={3,5,1,1};

    Polynomial b=Polynomial(3,y);
    cout<<endl<<endl<<a<<endl;
    cout<<b<<endl<<endl;
    cout<<a+b<<endl<<endl;

    (cout<<a)<<endl;

}