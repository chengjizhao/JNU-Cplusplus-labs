/*8.定义一个类Complex，包含私有成员变量real和imaginary，
以及友元函数void display(Complex c)用于输出复数。
在main函数中创建两个Complex对象，设置它们的实部和虚部，
然后调用display函数显示两个复数的和。*/
#include <iostream>  
  
class Complex 
{  
private:  
    double real;  
    double imaginary;  
  
public:  
    Complex(double r=0, double i=0):real(r),imaginary(i){}  
    double getReal() const 
    { 
        return real; 
    }  
    
    double getImaginary()const 
    { 
        return imaginary; 
    }  
  
    Complex operator+(const Complex& other) const 
    {  
        return Complex(real + other.real, imaginary + other.imaginary);  
    }  
  
    friend void display(Complex c);  
};  
  
void display(Complex c) 
{  
    std::cout<<"("<<c.getReal()<<"+"<<c.getImaginary()<<"i)"<<std::endl;  
}  
  
int main() 
{  
    Complex c1(3.0, 2.0);  
    Complex c2(1.0, -1.0);  
    std::cout << "c1: ";  
    display(c1);  
    std::cout << "c2: ";  
    display(c2);  
    Complex sum = c1 + c2;  
    std::cout << "Sum: ";  
    display(sum); 
  
    return 0;  
}