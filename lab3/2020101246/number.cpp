#include<iostream>  
#include<unordered_set>  
using namespace std;  


 int square(int x) {  
    return x * x;  
} 
// 计算数字的平方和  
int sumOfSquares(int n) {  
    int sum = 0;  
if (100>n>10)
{
   sum+=((n/10)*(n/10))+((n%10)*(n%10));
}
else if (n>=100)
{
    sum+=((n/100)*(n/100))+((n%100/10)*(n%100/10))+square(n%100%10);
}
else if(n<=10)
{
    sum=n;
}
    return sum;  
}  
  
  
//通过循环求取拆分后的平方和判断是否为忧伤  
bool isSad(int n) {  
    int p;
    p=sumOfSquares(n);
    while(p>10)
    {
        p=sumOfSquares(p);
    }
    if(p == 1) return true;  
    else if(p < 10) return false;   
}
  
int main() {  
    for(int i = 1; i <= 1000; ++i) {  
        if(isSad(i)) cout << "Number " << i << " is sad." << endl;  
        else cout << "Number " << i << " is happy." << endl;  
    }  
    return 0;  
}
