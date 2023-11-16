#include <iostream>
using namespace std;

class A {
public:
    int a;
};

class B : public A {
public:
    int b;
    virtual void func() {}
};

class C {
public:
    virtual void func() {}
};

class D : public C {
public:
    virtual void func1() {}
    virtual void func2() {}
};

class E : public A, public C {
public:
    int e;
};

class F : public virtual A {
public:
    int f;
};

int main() {
    cout << "sizeof(A) = " << sizeof(A) << endl;
    cout << "sizeof(B) = " << sizeof(B) << endl;
    cout << "sizeof(C) = " << sizeof(C) << endl;
    cout << "sizeof(D) = " << sizeof(D) << endl;
    cout << "sizeof(E) = " << sizeof(E) << endl;
    cout << "sizeof(F) = " << sizeof(F) << endl;
    return 0;
}
