#include<string>
using namespace std;
class Cperson
{
private:
    string IDnumber;
    int year,mounth,day;
    int sex;
    double height,weight;
public:
    string name;
    void showDate();
    void setDate();
    void size();
    Cperson(){
        name.clear();IDnumber.clear();
        year=0,mounth=0,day=0;
        sex=0;height=0;weight=0;
    }
    Cperson(string name1){
        name=name1;
        IDnumber.clear();
        year=0,mounth=0,day=0;
        sex=0;height=0;weight=0;
    }
};

