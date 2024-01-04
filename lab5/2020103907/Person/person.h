#include <string>

using namespace std;

class Person {
private:
    string name;
    string id;
    string birthday;
    char gender;
    double height;
    double weight;

public:
    // 构造函数
    Person();
    Person(const string &n);
    Person(const string &n, const string &id);
    Person(const string &n, const string &id, const string &b, char g, double h, double w);

    // 设置函数
    void setName(const string &n);
    void setID(const string &id);
    void setBirthday(const string &b);
    void setGender(char g);
    void setHeight(double h);
    void setWeight(double w);

    // 查询函数
    string getName() const;
    string getID() const;
    string getBirthday() const;
    char getGender() const;
    double getHeight() const;
    double getWeight() const;
};
