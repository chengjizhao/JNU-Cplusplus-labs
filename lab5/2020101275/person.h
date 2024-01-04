//person
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
