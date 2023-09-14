#include <iostream>
#include <vector>

bool isTargetNumber(int n) {
    for(int a=0;a<6;a++){
        int q = n%10;
        int r = n/1000;
        int e = n/100%10;
        int w = n/10%10;
        n = q*q+w*w+e*e+r*r;
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
