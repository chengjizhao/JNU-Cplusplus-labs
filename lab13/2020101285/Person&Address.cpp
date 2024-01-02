#include <iostream>
#include <memory>
#include <string>

class Address;

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Person " << name <<" ,age: "<<age<< " constructed." << std::endl;
    }
    ~Person() {
        std::cout << "Person " << name << " destructed." << std::endl;
    }

    void setAddress(std::weak_ptr<Address> addr) {
        
        address = addr.lock();
    }
    std::shared_ptr<Address> getAddress() const {
        return address;
    }
private:
    std::string name;
    int age;
    std::shared_ptr<Address> address;
};

class Address {
public:
    Address(const std::string& city, const std::string& street) : city(city), street(street) {
        std::cout << "Address " << street << ", " << city << " constructed." << std::endl;
    }
    ~Address() {
        std::cout << "Address " << street << ", " << city << " destructed." << std::endl;
    }

    void setPerson(std::weak_ptr<Person> person) {
        owner = person;
    }

private:
    std::string city;
    std::string street;
    std::weak_ptr<Person> owner;
};

int main() {
    // 创建 Person 实例
    std::shared_ptr<Person> person1 = std::make_shared<Person>("John", 25);
    std::shared_ptr<Person> person2 = std::make_shared<Person>("Alice", 30);
    std::shared_ptr<Person> person3 = std::make_shared<Person>("allen", 13);

    // 创建 Address，并为person设置地址
    std::shared_ptr<Address> addr1 = std::make_shared<Address>("City1", "Street1");
    std::shared_ptr<Address> addr2 = std::make_shared<Address>("City2", "Street2");
    person1->setAddress(addr1);
    ( person1->getAddress() ) -> setPerson(person1); //把所在地址的owner设为自己
    person2->setAddress(addr2);
    ( person2->getAddress() ) -> setPerson(person2);
    person3->setAddress(addr2);
    ( person3->getAddress() ) -> setPerson(person3);

    //使用weak_ptr控制Address;
    std::weak_ptr<Address> weakPtr_addr1 = addr1;
    std::weak_ptr<Address> weakPtr_addr2 = addr2;
    addr1 = nullptr;
    addr2 = nullptr;

    // 输出信息
    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout << "no person leave , 即person对象未销毁" << std::endl;
    std::cout << "person1 use_count: " << person1.use_count() << std::endl;
    std::cout << "person2 use_count: " << person2.use_count() << std::endl;
    std::cout << "person3 use_count: " << person3.use_count() << std::endl;
    std::cout << "addr1 use_count: " << weakPtr_addr1.use_count() << std::endl;
    std::cout << "addr2 use_count: " << weakPtr_addr2.use_count() << std::endl;

    std::cout<<"-----------------程序结束----------------------------"<<std::endl;
    return 0;
}

//可以看出，Address不会阻止Person的销毁，先销毁person，当address中没有person时自动销毁