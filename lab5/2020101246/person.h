#ifndef PERSON_H
#define PERSON_H

#include <string>

class Self {
    public:
        std::string name;
private :
    std::string id_number;
    std::string brith;
    std::string sex;
    int height;
    int weight;

public:
    Self();
    Self(std::string n, std::string i, std::string b, std::string g, int h, int w);
    void People();
    void Exchange(int n);
};
#endif