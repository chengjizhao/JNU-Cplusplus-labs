#include <iostream>
class Complex {
private:
    double real;
    double imaginary;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}
    double getReal() const {
        return real;
    }
    double getImaginary() const {
        return imaginary;
    }
    friend void display(Complex c);


    Complex operator+(const Complex& c)
      {
         Complex complex;
         complex.real = this->real + c.real ;
         complex.imaginary = this->imaginary + c.imaginary ;
         return complex;
      }
};
void display(Complex c) 
{
    std::cout << "(" << c.real << " + " << c.imaginary << "i)" << std::endl;
}
int main() {
    Complex c1(3.0, 2.0);
    Complex c2(1.0, -1.0);
    Complex sum = c1 + c2; 
    display(sum);
    return 0;
}