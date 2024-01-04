#include <string>
#include <cstdint>
#include <vector>
using namespace std;

class Person 
{
  private:
    string name;
    string id;
    string birthday;
    char gender;
    double height;
    double weight;

  public:
    //存储信息的结构体
    Person();
    Person(const string &n);
    Person(const string &n, const string &id);
    Person(const string &n, const string &id, const string &b, char g, double h, double w);

    void setName(const string &n);
    void setID(const string &id);
    void setBirthday(const string &b);
    void setGender(char g);
    void setHeight(double h);
    void setWeight(double w);

    // 实现查询功能
    string getName() const;
    string getID() const;
    string getBirthday() const;
    char getGender() const;
    double getHeight() const;
    double getWeight() const;

};
