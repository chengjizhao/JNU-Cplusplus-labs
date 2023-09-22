#include <iostream>
#include <vector>

using namespace std;

int determine(int n) {
    while (n!=1&&n!=4) {
        int sum=0;
        while (n > 0) {
            int digit=n%10;
            sum=sum+digit*digit;
            n=n/10;
        }
        n=sum; 
    }
    return n==1;
}

int main() {
    vector<int> happynumber; 
    vector<int> sadnumber;

    for (int i=0; i <1000; i++) {
        if (determine(i+1)) {
            happynumber.push_back(i+1);
        } else {
            sadnumber.push_back(i+1);
        }
    }

    cout << "幸福的数:" << endl;
    for (int i : happynumber) {
        cout << i << " "; 
    }
    cout << endl;

    cout << "忧伤的数:" << endl;
    for (int i : sadnumber) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}