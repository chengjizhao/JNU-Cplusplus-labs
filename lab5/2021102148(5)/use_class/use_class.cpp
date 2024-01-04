#include "use_class.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person(string name, string gender, string id, int year, int mouth, int day, double height, double weight)
    : name_(name),
      gender_(gender),
      id_(id),
      year_(year),
      mouth_(mouth),
      day_(day),
      height_(height),
      weight_(weight)
{
}

Person::Person()
    : name_("zxx"),
      gender_("girl"),
      id_("13253513978659813365491"),
      year_(2012),
      mouth_(12),
      day_(02),
      height_(168),
      weight_(50)
{
}

void Person::set()
{
    cout << "姓名：" << endl;
    cin >> name_;
    cout << "性别：" << endl;
    cin >> gender_;
    cout << "身份证：" << endl;
    cin >> id_;
    cout << "出生日期（年、月、日）（每输入一个数字按回车）：" << endl;
    cin >> year_;
    cin >> mouth_;
    cin >> day_;
    cout << "身高(cm)" << endl;
    cin >> height_;
    cout << "体重(kg):" << endl;
    cin >> weight_;
}

void Person::search()
{
    cout << " 姓名：" << name_ << " 性别：" << gender_ << " 身份证：" << id_ << " 出生日期：" << year_ << "," << mouth_ << "," << day_ << " 身高：" << height_ << "  体重:" << weight_ << endl;
}

void Person::set2(Person &p)
{
    cout << "请输入" << p.name_ << "的相关信息" << endl;
    cout << "性别：" << endl;
    cin >> gender_;
    cout << "身份证：" << endl;
    cin >> id_;
    cout << "出生日期（年、月、日）（每输入一个数字按回车）：" << endl;
    cin >> year_;
    cin >> mouth_;
    cin >> day_;
    cout << "身高(cm)" << endl;
    cin >> height_;
    cout << "体重(kg):" << endl;
    cin >> weight_;
}

void Person::size(Person &p)
{
    cout << "姓名字节数：" << sizeof(p.name_) << " 性别字节数：" << sizeof(p.gender_)
         << " 身份证字节数：" << sizeof(id_) << " 出生日期字节数：" << sizeof(year_) << " 出生日期字节数"
         << sizeof(mouth_) << " 出生日期字节数：" << sizeof(day_) << " 身高字节数：" << sizeof(height_) << "  体重字节数:" << sizeof(weight_) << endl;
}