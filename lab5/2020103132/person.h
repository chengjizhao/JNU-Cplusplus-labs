/*头文件和实现文件分开，实现一个类 person， 他有名字，身份证号， 出生年月日，性别，身高，
体重，这些数据只有名字是public的； 可以通过查询和设置函数，查询设置所有这些属性；
类具有多种构造函数。在主程序里面用不同的初始化方法实现创建多个person对象，打印每个对象占用的
存储空间是多大？并解释为什么对象的尺寸是这么大？
*/
#ifndef  PERSON_H_
#define  PERSON_H_
#include<string>

using namespace std;

class person
{
    private:
    int id;
    int birthday;
    string gender;
    int height;
    int weight;
    public:
    string name;
    public:
    Person();
    Person(string n);
    Person(string n, int i, int b, string g, int h, int w);

    void setId(string i);
    string getId() const;

    void setBirthday(string b);
    string getBirthday() const;

    void setGender(string g);
    string getGender() const;

    void setHeight(int h);
    int getHeight() const;

    void setWeight(int w);
    int getWeight() const;

} ;

#endif