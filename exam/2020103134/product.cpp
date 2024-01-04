#include<iostream>
#include<thread>
#include<random>
void add(){

}
void take(){

}
int main(){
    int max=20;
    thread productor(add);
    productor.join();
    thread consumer1(take);
    consumer1.join();
    thread consumer2(take);
    thread consumer3(take);
    thread consumer4(take);
    return 0;
}