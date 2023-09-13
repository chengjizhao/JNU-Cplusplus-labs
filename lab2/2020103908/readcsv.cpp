#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()  {
   ifstream ifs;
   ifs.open("students.csv", ios::in);
   if (ifs.is_open())
   {
       string line;
       while (getline(ifs, line))
       {
           cout << line << endl;
       }
   }
   else
   {
       cout << "failed to open the file" << endl;
   }
   ifs.close();


   return 0;
}