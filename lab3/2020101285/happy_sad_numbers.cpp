#include<iostream>
#include<vector>

using namespace std;

int calculateNewNumber(int n);
bool isSad(int n);

int main(){
    int n = 1;
    vector<int> sadNumber;
    vector<int> happyNumber;
    while (n <= 1000){
        if(isSad(n))
            sadNumber.push_back(n);
        else
            happyNumber.push_back(n);
        n++;
    }
    cout<<"1000以内幸福的数有:"<<endl;
    for (int i = 0; i < happyNumber.size(); i++)
    {
        cout<<happyNumber[i]<<" ";
    }
    cout<<endl<<"1000以内忧伤的数有:"<<endl;   
    for (int i = 0; i < sadNumber.size(); i++)
    {
        cout<<sadNumber[i]<<" ";
    }    

    return 0; 
}

bool isSad(int n){
    while (n>9)
        n = calculateNewNumber(n);

    if(n==1)
        return true;
    else
        return false;
}

int calculateNewNumber(int n){
    int NewNumber = 0;
    while (n)
    {
        NewNumber += (n%10) * (n%10);
        n = n/10;
    }
    return NewNumber;
}