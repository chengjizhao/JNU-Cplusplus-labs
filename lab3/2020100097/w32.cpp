#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;

int sumset(int i)
{
    int sum=0;
    while (i>0) 
    {
        int digit=i% 10;
        sum+=digit*digit;
        i/=10;
    }
    return sum;
}

bool Sadset(int n)
{
    std::unordered_set<int> seen;
    while (n!=1 && seen.find(n)==seen.end())
    {
        seen.insert(n);
        n=sumOfSquares(n);
    }
    return n==1;
}


int main()
{
    std::cout << "Around1000sadnumber：\n";
    for (int j=1; j<=1000; ++j) 
    {
        if (Sadset(l)) 
        {
            std::cout << j << " ";
        }
    }std::cout << "\n";

    std::cout << "Around1000happynumber：\n";
    for (int j=1;j<=1000;++j) 
    {
        if (!Sadset(j)) 
        {
            std::cout << i << " ";
        }
    }std::cout << "\n";
    return 0;
}