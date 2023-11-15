#include <iostream>

class GeneralClass {
public:
    int x;
    void print() {
        std::cout << "GeneralClass: x = " << x << std::endl;
    }
};

int main() {
    GeneralClass generalObj;
    generalObj.x = 1;
    generalObj.print();

    return 0;
}