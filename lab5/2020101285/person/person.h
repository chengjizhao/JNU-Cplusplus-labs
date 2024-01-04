#include<iostream>
using namespace std;

class person
{
private:
    string id;
    char gender; // 'm' or 'w'
    float height;
    float weight;
    int birth_date; //20201011
public:
    person(); //通过键盘交互初始化对象
    person(string id); //只有身份证号，其他值为默认值
    person(string name,string id,char gender,float height,float weight,int birth_date);

    string get_name();
    void set_name(string name);

    string get_id();
    void set_id(string id);

    char get_gender();
    void set_gender(char gender);

    float get_height();
    void set_height(float height);

    float get_weight();
    void set_weight(float weight);

    int get_birth_date();
    void set_birth_date(int date);
    void set_birth_date(int year,int month,int day);
    
    string name;
};


void show_Info(person p);