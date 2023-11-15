# 内存对象模型
## 简单类
### 简介
一般来说，一个最简单的类的起始地址即为其第一个变量的地址，且类中不包含成员函数的地址或大小。

### 代码
~~~cpp
//类定义
class Normal_Class
{
public:
    int param;
    void testFunc()
    {
        cout << "testFunc is called!" << endl;
    }
};
~~~
~~~cpp
//主函数
int main()
{   
    Normal_Class dummy1;
    int size = sizeof(dummy1);

    int* pClass = reinterpret_cast<int*>(&dummy1);/*get ClassAddr*/
    int* pParam= &dummy1.param;/*get ParamAddr*/

    Funcpointer pFunc = &Normal_Class::testFunc;/*get FuncAddr*/

    cout << "This is ClassSize: " << size << endl;
    cout << "This is ClassAddr: " << pClass << endl;
    cout << "This is ParamAddr: " << pParam << endl;
    cout << "This is FuncAddr : " << &pFunc << endl;
    (dummy1.*pFunc)();/*Use FuncAddr to call this func*/

    return 0;
}
~~~


### 输出

> This is ClassSize: 4
>
> This is ClassAddr: 0x61fe04
>
> This is ParamAddr: 0x61fe04
>
> This is FuncAddr : 0x61fdf0
>
> testFunc is called!

可见实际输出与预期相符合。

### 内存结构模型
![Normal_Class](D:\C++Files\Homework\work10\2021100731\pics\1_Normal_Class.png)