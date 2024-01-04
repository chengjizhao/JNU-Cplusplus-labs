#include <iostream>

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing shape" << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing square" << std::endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw();  
    shape2->draw();  

    delete shape1;
    delete shape2;

    return 0;
}