#include <iostream>
using namespace std;

class device {
 public:
  int date;
  device(int d) : date(d){};
};

class computer : public virtual device {
 public:
  computer(int d) : device(d){};
};

class phone : public virtual device {
 public:
  phone(int d) : device(d){};
};

class Smart_device : public virtual computer, public virtual phone {
 public:
  Smart_device(int d) : device(d), computer(d), phone(d){};
  void runAPP() { cout << "Smart_device has run" << endl; }
};

int main() {
  Smart_device obj(1);
  obj.runAPP();
}