#include <iostream>
using namespace std;

class A {
private:
    int x;
    void privatefction() {
        cout << "x = " << x << endl;
    }
public:
    A(int _x) : x(_x) {}
    friend void publicfctiona(A* a);
    static void publicfctionb(A* a) {
        a->privatefction();
    }
};

void publicfctiona(A* a) {
    a->privatefction();
}

int main() {
    A a(10);
    void (*p)(A*) = publicfctiona;
    p(&a);
    p = A::publicfctionb;
    p(&a);
    return 0;
}