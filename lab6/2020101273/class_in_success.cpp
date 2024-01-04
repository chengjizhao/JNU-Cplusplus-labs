#include <iostream>
using namespace std;
 
class Game {
public:
	Game() 
    {
		PSkill[1] = &Game::SkillOne;
		PSkill[2] = &Game::SkillTwo;
		PSkill[3] = &Game::SkillThree;
		PSkill[4] = &Game::SkillFour;
	}
    ~Game(){ cout << "bye!";}
	void select(int index) 
    {
		if (index >= 1 && index <= 4) {
			(this->*PSkill[index])();
		}
	}
 
private:
	void SkillOne()   { cout << "Use skill one.." << endl; }
	void SkillTwo()   { cout << "Use skill Two.." << endl; }
	void SkillThree() { cout << "Use skill Three.." << endl; }
	void SkillFour()  { cout << "Use skill Four.." << endl; }
 
	void (Game::*PSkill[4])();
};
 
int main() {
	Game newOne;
	newOne.select(3);
	newOne.select(1);
	newOne.select(4);

	return 0;
}