//
// Created by fkris on 10/5/2026.
//
#include <iostream>
#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial(int degree, const double coefficients[]) {
    this->capacity=degree+1;
    this->coefficients = new double[this->capacity]{};
    for (int i = 0; i <= degree; i++) {
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity=that.capacity;
    this->coefficients = new double[this->capacity]{};
    for (int i = 0; i <that.capacity; i++) {
        this->coefficients[i] = that.coefficients[i];
    }
}

Polynomial::~Polynomial() {
    delete []coefficients;
}

int Polynomial::degree() const {
    return this->capacity-1;
}

double Polynomial::evaluate(double x) const {
    double result = 0;

    for (int i=this->degree();i>=0;i--) {
        result*=x;
        result+=this->coefficients[i];

    }
    return result;
}

Polynomial Polynomial::derivative() const {
    Polynomial temp(this->degree()-1,this->coefficients);
    temp.coefficients[0]=temp.coefficients[1]+temp.coefficients[0];
    for (int i=1; i<temp.capacity-1;i++) {
        temp.coefficients[i]=temp.coefficients[i+1]*(i+1);
    }
    temp.coefficients[temp.degree()]=this->coefficients[temp.degree()+1]*(temp.degree()+1);
    return temp;
}

double Polynomial::operator[](int index) const {
    if (index<0) {cout<<"HIBA";return -1;}
    if (index>this->capacity) return 0;
    return coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    Polynomial temp(a.degree(),a.coefficients);
    for (int i=0;i<=a.degree();i++)
        temp.coefficients[i]=0-a.coefficients[i];
    return temp;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    if(a.capacity>b.capacity) {
        Polynomial result(a.capacity,a.coefficients);
        for (int i=0;i<b.capacity;i++) {
            result.coefficients[i] += b.coefficients[i];
        }
        return result;
    }
    Polynomial result(b.capacity,b.coefficients);
    for (int i=0;i<a.capacity;i++) {
        result.coefficients[i] += a.coefficients[i];
    }
    return result;

}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    if(a.capacity>b.capacity) {
        Polynomial result(a.capacity,a.coefficients);
        for (int i=0;i<b.capacity;i++) {
            result.coefficients[i] -= b.coefficients[i];
        }
    }
    Polynomial result(b.capacity,b.coefficients);
    for (int i=0;i<a.capacity;i++) {
        result.coefficients[i] -= a.coefficients[i];
    }
    return result;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    if(a.capacity>b.capacity) {
        Polynomial result(a.capacity,a.coefficients);
        for (int i=0;i<b.capacity;i++) {
            result.coefficients[i] *= b.coefficients[i];
        }
    }
    Polynomial result(b.capacity,b.coefficients);
    for (int i=0;i<a.capacity;i++) {
        result.coefficients[i] *= a.coefficients[i];
    }
    return result;
}

auto operator<<(ostream &out, const Polynomial &what) -> ostream & {
    bool first=true;
    for (int i=what.degree();i>=0;i--) {

        if (what.coefficients[i]==1) if (first){out<<"x^"<<i;first=false;}
                                        else out<<"+x^"<<i;


        else if (what.coefficients[i]==-1) {out<<"-x^"<<i;first=false;}

            else if (first){out<<what.coefficients[i]<<"x^"<<i;first=false;}
                    else {out<<"+"<<what.coefficients[i]<<"x^"<<i;}
    }

    return out;
}

