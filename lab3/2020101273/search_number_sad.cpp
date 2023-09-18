#include<iostream>
#include<vector>
#include<algorithm>
#include<ostream>
#include <iterator>
using namespace std;

int main()
{
    int i;
    int a,b,c,d,m;
    vector<int> vec1;
	vector<int> vec2;
    vector<int> vec3;
    vector<int>::iterator it;
    for(i=1;i<=1000;++i)
    {
        vec3.clear();
        a = i/1000;
        b = i/100%10;
        c = i/10%10;
        d = i%10;
        m = a*a + b*b + c*c + d*d;
        if(m==1)
        {
           vec2.push_back(i);
        }
        else
        while(m!=1)
        {
            a = m/1000;
            b = m/100%10;
            c = m/10%10;
            d = m%10;
            m = a*a + b*b + c*c + d*d;
            if(m==1)
                {  
                    vec2.push_back(i);
                    break;
                }
            else
                {
                    it = find(vec3.begin(), vec3.end(), m);
                    if (it != vec3.end())
                    {
                        vec1.push_back(i);
                        break;               
                    }
                    else
                    {
                        vec3.push_back(m);
                    }
                }
        }

    }

    cout << "1000内悲伤的数：" << endl;
    for(int i = 0; i < vec2.size(); ++i) 
    {
        cout << vec2[i] << " ";
    }
    cout << endl << "个数：" << vec2.size() << endl;
    cout << "1000内幸福的数：" << endl;
    for(int i = 0; i < vec1.size(); ++i) 
    {
        cout << vec1[i] << " ";
    }
    cout << endl << "个数：" << vec1.size() ;
    return 0;
}