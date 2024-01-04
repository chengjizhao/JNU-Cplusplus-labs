/*虚指针的作用是它指向了一个虚函数表的头部，通过在虚函数表中找到真正的代码
它的实例应该还包含一个虚函数表指针*/
#include <iostream>  
using namespace std;  
class Attack {  
public:  
    virtual void attack() = 0;  
};  

class NormalAttack : public Attack {  
public:  
    void attack() override {  
        cout << "普通攻击" << endl;  
    }  
};  
class SpecialAttack : public Attack {  
public:  
    void attack() override {  
        cout << "特殊攻击" << endl;  
    }  
};  
class Character {  
private:  
    Attack* attack; 
public:  
    Character(Attack* attack) : attack(attack) {}  
    void attackEnemy() {  
        attack->attack();
    }  
};  
int main() {   
    NormalAttack normalAttack;  
    SpecialAttack specialAttack;  
    Character character(&normalAttack);  
    character.attackEnemy();   
    Character character1(&specialAttack);  
    character1.attackEnemy();   
    return 0;  
}