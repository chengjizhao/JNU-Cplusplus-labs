#include<iostream>  
#include<unordered_set>  
using namespace std;  
  
// 计算数字的平方和  
int sumOfSquares(int n) {  
    int sum = 0;  
if (100>n>10)
{
   sum+=(n/10)*(n%10);
}
else if (1000>n>100)
{
    sum+=(n/100)*(n%100/10)*(n%100%10);
}
else (n<10)
{
    sum=n;
}
    return sum;  
}  
  
// 判断数字是否是忧伤的，使用深度优先搜索  
bool isSad(int n) {  
    p=sumOfSquares(n);
    if(p == 1) return false;  
    if(p < 10) return true;  
    for(int i = 0; i < n; ++i) {  
        if(isSad(i) && isSad(n - i)) return true;  
    }  
    return false;  
}  
  
// 判断数字是否是幸福的，即不是忧伤的  
bool isHappy(int n) {  
    return !isSad(n);  
}  
  
int main() {  
    for(int i = 1; i <= 1000; ++i) {  
        if(isHappy(i)) cout << "Number " << i << " is happy." << endl;  
        else cout << "Number " << i << " is sad." << endl;  
    }  
    return 0;  
}