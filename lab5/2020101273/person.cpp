#include "person.h"

// 默认构造函数1  
Person::Person()
{  
    name = "Unknown";  
    id = "Unknown";  
    birthdate = "Unknown";  
    gender = "Unknown";  
    height = 0.0;  
    weight = 0.0;  
}

// 带名字和身份的构造函数2  
Person::Person(const string& name) 
{  
    this->name = name;  
    id = "Unknown";  
    birthdate = "Unknown";  
    gender = "Unknown";  
    height = 0.0;  
    weight = 0.0;  
}

// 带名字和出生年月日的构造函数3  
Person::Person(const string& name, const string& birthdate) 
{  
    this->name = name;  
    id = "Unknown";  
    this->birthdate = birthdate;  
    gender = "Unknown";  
    height = 0.0;  
    weight = 0.0;  
}

// 带名字、出生年月日和性别的构造函数4  
Person::Person(const string& name, const string& birthdate, const string& gender) 
{  
    this->name = name;  
    id = "Unknown";  
    this->birthdate = birthdate;  
    this->gender = gender;  
    height = 0.0;  
    weight = 0.0;  
}

// 带名字、出生年月日、性别和身高的构造函数5  
Person::Person(const string& name, const string& birthdate, \
const string& gender, double height) 
{  
    this->name = name;  
    id = "Unknown";  
    this->birthdate = birthdate;  
    this->gender = gender;  
    this->height = height;  
    weight = 0.0;  
}

// 带名字、身份、出生年月日、性别、身高和体重的构造函数6  
Person::Person(const string& name, const string& id, const string& birthdate, \
const string& gender, double height, double weight) 
{  
    this->name = name;  
    this->id = id;  
    this->birthdate = birthdate;  
    this->gender = gender;  
    this->height = height;  
    this->weight = weight;  
}

Person::~Person()
{
   //cout << "Bye" << "\n";
}

// 打印对象占用的存储空间大小  
void printSize(const Person& person) 
{  
    std::cout << "Size of Person: " << sizeof(person) << " bytes" << std::endl;  
}

int main() 
{  
    string i;
    Person person1;  
    Person person2("John");  
    Person person3("Ante", "1995-01-01");  
    Person person4("Jack", "2000-01-01", i);
    i="男";
    Person person5("Tom", "1993-01-01", "男", 170.0);
    Person person6("Li", "4401111997**","1997-01-01", "女", 170.0, 65.0);

    cout << person1.getName() << ',';
    cout << person1.getID() << ',';
    cout << person1.getBirthdate() << ',';
    cout << person1.getGender() << ',';
    cout << person1.getHeight() << ',';
    cout << person1.getWeight() << ',';
    printSize(person1);
    person1.setName("Mike");
    cout << "person1.name:" << person1.name << '\n';

    cout << person2.getName() << ',';
    cout << person2.getID() << ',';
    cout << person2.getBirthdate() << ',';
    cout << person2.getGender() << ',';
    cout << person2.getHeight() << ',';
    cout << person2.getWeight() << ',';
    printSize(person2);
    person2.setID("4401111999**");
    cout << "person2.ID:" <<person2.getID() << '\n';

    cout << person3.getName() << ',';
    cout << person3.getID() << ',';
    cout << person3.getBirthdate() << ',';
    cout << person3.getGender() << ',';
    cout << person3.getHeight() << ',';
    cout << person3.getWeight() << ',';
    printSize(person3);

    cout << person4.getName() << ',';
    cout << person4.getID() << ',';
    cout << person4.getBirthdate() << ',';
    cout << person4.getGender() << ',';
    cout << person4.getHeight() << ',';
    cout << person4.getWeight() << ',';
    printSize(person4);

    cout << person5.getName() << ',';
    cout << person5.getID() << ',';
    cout << person5.getBirthdate() << ',';
    cout << person5.getGender() << ',';
    cout << person5.getHeight() << ',';
    cout << person5.getWeight() << ',';
    printSize(person5);

    cout << person6.getName() << ',';
    cout << person6.getID() << ',';
    cout << person6.getBirthdate() << ',';
    cout << person6.getGender() << ',';
    cout << person6.getHeight() << ',';
    cout << person6.getWeight() << ',';
    printSize(person6);

}