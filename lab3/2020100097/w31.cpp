 #include<iostream>
#include<list>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<iterator> 

using namespace std;  

int main()
 {
    int i,j=0;
    vector<int> myVector;
    list<int> myList;
    srand(static_cast<unsigned int>(time(nullptr)));
    clock_t start_time=clock();
    for(i=0;i<10000;i++) 
    {
        int random_value=rand();
        myVector.insert(myVector.begin()+(rand()%(myVector.size()+1)),random_value);
    }
    clock_t end_time=clock();
    double vector_insert_time=static_cast<double>(end_time - start_time)/CLOCKS_PER_SEC;
    start_time=clock();
    for (i=0;i<10000;i++)
    {
        int random_value=rand();
        myList.insert(next(myList.begin(),rand()%(myList.size()+1)),random_value);
    }
    end_time=clock();
    double list_insert_time=static_cast<double>(end_time - start_time)/CLOCKS_PER_SEC;
    cout << "vectorset "<< 10000 << "needs: " << vector_insert_time << "s\n";
    cout << "listset " << 10000 << "needs: " << list_insert_time << "s";
    return 0;
}