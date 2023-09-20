#include <iostream>
#include <vector>

bool isTargetNumber(int n) {
    for(int c=0;c<6;c++){
        int p = n%10;
        int u = n/1000;
        int t = n/100%10;
        int g = n/10%10;
        n = p*p+g*g+t*t+u*u;
        if (n == 1) {
            
            return  true;
        }
    }return false;
}



int main() {
 std::vector<int> targetNumbers;
 for (int i =1; i <=1000; i++) {
 if (isTargetNumber(i)) {
 targetNumbers.push_back(i);
 }
 }

 std::cout << "1000以内的目标数有：" <<std::endl;
 for (const auto& number : targetNumbers) {
 std::cout << number << " ";
 }
 std::cout << std::endl;

}