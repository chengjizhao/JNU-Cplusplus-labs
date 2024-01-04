#include <iostream>

using namespace std;

class Shape {
public:
    virtual void display() {
        cout << "Shape" << endl;
    }
};

class Line : public Shape {
public:
    virtual void display() {
        cout << "Line" << endl;
    }
};

int main() {
    Line line;
    uintptr_t *vptr = reinterpret_cast<uintptr_t *>(&line);
    uintptr_t *vtable = reinterpret_cast<uintptr_t *>(*vptr);

    typedef void (*FuncPtr)();
    FuncPtr func = reinterpret_cast<FuncPtr>(vtable[0]);
    func();

    return 0;
}