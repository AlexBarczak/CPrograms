#include <iostream>
#include <cstdlib>
#include "Complex.h"
using namespace std;

void Complex::set_real(double r){
    real = r;
}
double Complex::get_real(){
    return real;
}
void Complex::set_img(double i){
    img = i;
}
double Complex::get_img(){
    return img;
}

Complex::Complex() {
    real = 0;
    img = 0;
}

Complex::Complex(double r, double i) {
    this->real = r;
    this->img = i;
}

ostream& operator<<(ostream &output, const Complex &c) {
    output << c.real;
    if (c.img == 0)
    {
        output << '+' << c.img << 'i' << endl;
        return output;
    }
    if (c.img > 0)
    {
        output << '+';
    }else{
        output << '-';
    }
    if (abs(c.img) != 1)
    {
        output << abs(c.img);
    }
    output << 'i';

    return output;
}

Complex Complex::operator+(const Complex& c) {
    Complex complex(this->real + c.real, this->img +c.img);
    return complex;
}
