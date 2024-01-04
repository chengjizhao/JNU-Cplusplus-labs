// person.cpp
#include "person.h"
using namespace std;

Person::Person(const string& name) : name(name) {}

Person::Person(const string& name, const string& id, const string& birthdate, const string& gender, double height, double weight)
        : name(name), id_(id), birthdate_(birthdate), gender_(gender), height_(height), weight_(weight) {}

void Person::set_id(const string& id) {
    id_ = id;
}

void Person::set_birthdate(const string& birthdate) {
    birthdate_ = birthdate;
}

void Person::set_gender(const string& gender) {
    gender_ = gender;
}

void Person::set_height(double height) {
    height_ = height;
}

void Person::set_weight(double weight) {
    weight_ = weight;
}

string Person::get_id() const {
    return id_;
}
string Person::get_birthdate() const {
	return birthdate_;
}
string Person::get_gender() const {
	return gender_;
}
double Person::get_height() const{
	return height_;
}
double Person::get_weight() const{
	return weight_;
}

int main()
{
	Person inita;
	inita.name="xiaozhang";
	inita.set_id("aaa");
	inita.set_birthdate("2002y11y1d");
	inita.set_gender("man");
	inita.set_height(175);
	inita.set_weight(65);
	cout<<inita.name<<endl;
	cout<<inita.get_id()<<endl;
	cout<<inita.get_birthdate()<<endl;
	cout<<inita.get_gender()<<endl;
	cout<<inita.get_height()<<endl;
	cout<<inita.get_weight()<<endl;
	cout<<sizeof(inita)<<endl;
	//name,id,birthdate,gender都是string型，占据储存空间32个bite，height，weight，为double型，占据储存空间8个bite，故inita占据储存空间144个bite
	return 0;
}