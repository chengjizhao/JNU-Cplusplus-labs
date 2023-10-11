#include"lab5.h"
#include"person.h"
void person::getID(int I)
{
 this->ID=I;
}

void person::getName(string N)
{
 this->Name=N;
}

void person::getBirthday(string B)
{
 this->Birthday=B;
}

void person::getGender(string G)
{
 this->Gender=G;
}

void person::getHeight(int H)
{
 this->Height=H;
}

void person::getWeight(int W)
{
 this->Weight=W;
}

void person::show()
{
    std::cout << "名字:" << this->Name <<  endl << "性别：" << this->Gender  << endl << "身份证：" << this->ID << endl << "生日：" << this->Birthday << endl << "身高：" << this->Height << endl << "体重：" <<this->Weight << endl;
}

person::person()
{
}

person::~person()
{
}

person::person(string Name, int ID, string Birthday, string Gender, int Height, int Weight)
{
    this->Name=Name;
    this->ID=ID;
    this->Birthday=Birthday;
    this->Gender=Gender;
    this->Height=Height;
    this->Weight=Weight;
}

person::person(const person &a)
{
    this->Name=a.Name;
    this->ID=a.ID;
    this->Birthday=a.Birthday;
    this->Gender=a.Gender;
    this->Height=a.Height;
    this->Weight=a.Weight;
}
