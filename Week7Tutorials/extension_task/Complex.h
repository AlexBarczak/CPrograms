#ifndef COMPLEX_H 
#define COMPLEX_H
class Complex {
    private:
        double real;
        double img;
    public:
        void set_real(double r);
        double get_real();
        void set_img(double i);
        double get_img();
        Complex();
        Complex(double r, double i);

        friend std::ostream& operator<<(std::ostream &output, const Complex &c);
        Complex operator+(const Complex& c);
};
#endif
