#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
    private:
        string person_ID;
        string birthday;
        string gender;
        double height;
        double weight;
    public:
        string name;
        Person();
        Person(string m_name);
        Person(string m_name, string m_person_ID, const string m_birthday, const string m_gender, double m_height, double m_weight);
        void set_name(string m_name);
        string get_name() const;
        void set_person_ID(string m_person_ID);
        string get_person_ID() const;
        void set_birthday(string m_birthday);
        string get_birthday() const;
        void set_gender(string m_gender);
        string get_gender() const;
        void set_height(double m_height);
        double get_height() const;
        void set_weight(double m_weight);
        double get_weight() const;
};

#endif
