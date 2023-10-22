/*编程验证能否通过函数指针的方式规避“只有类的内部函数才能调用私有成员函数”规则，即能否
通过把私有成员函数的指针付给一个外部函数指针的方式调用私有成员函数。如果不能，请示例出正确
的写法。*/

#include <iostream>
using namespace std;

class verify
{
    private:
    int secret=1;
    void getSecret();
    public:
    int pub;
};

void verify::getSecret()
{
    cout<<secret<<endl;
}
void Get(verify::*getSecret(),verify &V)//此处报错，因此不能用外部指针调用私有成员
{
    (V.*getSecret)();
}
int main()
{
    verify V
    Get(&verify::getSecret,V);
    return 0;
}
