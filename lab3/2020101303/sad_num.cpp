#include<iostream>
#include<vector>
using namespace std;
int sum_of_squares(int num)
{
    int sum = 0;
    while (num != 0)
    {
        int a = num % 10;
        sum = sum + a * a;
        num = num / 10;
    }
    return sum;
}
int judge_sad(int num, vector<int>& Vector)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        for (const auto& n : Vector)
        {
            if (n == num)
            {
                return 0;
            }
        }
        Vector.push_back(num);
        int sum = sum_of_squares(num);
        return judge_sad(sum, Vector);
    }
}
int main()
{
    
    cout << "1000以内忧伤的数：" << endl;
    for (int i=1; i<=1000; i++)
    {
        vector<int> sad;
        if(judge_sad(i, sad))
        {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "1000以内幸福的数：" << endl;
    for (int i=1; i<=1000; i++)
    {
        vector<int> happy;
        if(!judge_sad(i, happy))
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
