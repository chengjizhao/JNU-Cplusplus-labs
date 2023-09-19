#include <iostream>
#include <vector>
#include <algorithm>

bool isHappy(int n) 
{
    std::vector<int> history;

    while (n!= 1&&std::find(history.begin(), history.end(), n)==history.end()) 
    {
        history.push_back(n);

        int sum = 0;
        while (n > 0) 
        {
            int k=n%10;
            sum=sum+k*k;
            n=n/10;
        }

        n=sum;
    }

    return n==1;
}

int main() 
{
    std::vector<int> happyNumbers;
    std::vector<int> worryNumbers;

    for (int i=1;i<=1000;i++) 
    {
        if (isHappy(i))
            happyNumbers.push_back(i);
        else
            worryNumbers.push_back(i);
    }

    std::cout << "幸福数：";
    for (int num : happyNumbers)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "忧伤数：";
    for (int num : worryNumbers)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}