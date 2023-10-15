#ifndef PERSON_H
#define PERSON_H
#include<string>
using namespace std;
class person
{
    private:
    string id_;
    string birthday_;
    string gender_;
    double height_;
    double weight_;

    public:
    //构造函数
    string name_;
    person();
    person(const string &name,const string &id,const string &bd,const string &g,double h,double w);
    //查询函数
    string get_name() const;
    string get_id() const;
    string get_birthday() const;
    string get_gender() const;
    double get_height() const;
    double get_weight() const;
    //设置函数
    void set_name(const string &name);
    void set_id(const string &id);
    void set_birthday(const string &bd);
    void set_gender(const string &g);
    void set_height(double h);
    void set_weight(double w);
};




#endif