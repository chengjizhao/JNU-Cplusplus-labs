#include <iostream>

#include "shape.h"
using namespace std;

int main() {
  double rr;
  int n;
  do {
    cout << "请输入要计算的图形：" << endl
         << "圆形：1" << endl
         << "矩形：2" << endl
         << "三角形：3" << endl
         << "结束：4" << endl;
    cin >> n;
    switch (n) {
      case 1: {
        double rr;
        cout << "请输入半径：";
        cin >> rr;
        cout << endl;
        circle c(rr);
        c.circle_Are();
        c.circle_Cir();
        break;
      }
      case 2: {
        double a, b;
        cout << "请输入长与宽：";
        cin >> a >> b;
        cout << endl;
        rectangle re(a, b);
        re.rectangle_Are();
        re.rectangle_Cir();
      }

      case 3: {
        double x, y, z;
        cout << "请输入三边长：";
        cin >> x >> y >> z;
        cout << endl;
        do {
          if ((x + y) > z && (z + y) > x && (x + z) > y)
            break;
          else {
            cout << "错误，请重新输入边长：";
            cin >> x >> y >> z;
          }
        } while (1);
        triangle t(x, y, z);
        t.triangle_Are();
        t.triangle_Cir();
      }
      default:
        break;
    }
  } while (n != 4);
}