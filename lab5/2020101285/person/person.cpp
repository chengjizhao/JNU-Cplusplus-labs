#include"person.h"

person::person(){
    cout<<"input name: ";
    cin>>this->name;

    cout<<"input id: ";
    cin>>this->id;

    cout<<"input gender(m/w): ";
    cin>>this->gender;

    cout<<"input height: ";
    cin>>this->height;

    cout<<"input weighr: ";
    cin>>this->weight;

    cout<<"input birth date: ";
    cin>>this->birth_date;
}

person::person(string id){
    this->id = id;
}

person::person(string name,string id,char gender,float height,float weight,int birth_date){

    this->name = name;
    this->id = id;
    this->gender = gender;
    this->height = height;
    this->weight = weight;
    this->birth_date = birth_date;
}

string person::get_name(){
    return this->name;
}

void person::set_name(string name){
    this->name = name;
}

string person::get_id(){
    return this->id;
}

void person::set_id(string id){
    this->id = id;
}

char person::get_gender(){
    return this->gender;
}

void person::set_gender(char gender){
    this->gender = gender;
}

float person::get_height(){
    return this->height;
}

void person::set_height(float height){
    this->height = height;
}

float person::get_weight(){
    return this->weight;
}

void person::set_weight(float weight){
    this->weight = weight;
}

int person::get_birth_date(){
    return this->birth_date;
}

void person::set_birth_date(int birth_date){
    this->birth_date = birth_date;
}

void person::set_birth_date(int year,int month,int day){
    this->birth_date = year*10000 + month*100 + day;
}

void show_Info(person p){
    cout<<p.name<<"'s information details are follow "<<endl;
    cout<<"id: "<<p.get_id()<<endl;
    cout<<"gender: "<<p.get_gender()<<endl;
    cout<<"height: "<<p.get_height()<<endl;
    cout<<"weight: "<<p.get_weight()<<endl;
    cout<<"birth date: "<<p.get_birth_date()<<endl;
}