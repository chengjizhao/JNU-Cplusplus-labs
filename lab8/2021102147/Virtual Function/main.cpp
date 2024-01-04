#include "SampleClass.h"
#include <iostream>


using std::cout, std::endl;


int main() {
    SampleClass sc;
    SampleClassExtend sce;
	SampleClassExtend2 sce2;
   
    void (SampleClass::*fptr1)() = &SampleClass::VirtualMethod;
    void (SampleClass:: * fptr2)() = &SampleClass::VirtualMethod2;
	cout << "基类的虚函数地址:" << endl;
    cout << reinterpret_cast<void*>(sc.*fptr1) << endl;
    cout << reinterpret_cast<void*>(sc.*fptr2) << endl;
	
    void (SampleClassExtend::*fptr_ex1)() = &SampleClassExtend::VirtualMethod;
    void (SampleClassExtend::*fptr_ex2)() = &SampleClassExtend::VirtualMethod2;
	cout << "覆盖了第一个函数的子类的虚函数地址：" << endl;
    cout << reinterpret_cast<void*>(sce.*fptr_ex1) << endl;
    cout << reinterpret_cast<void*>(sce.*fptr_ex2) << endl;

	void (SampleClassExtend2::*fptr_ex2_1)() = &SampleClassExtend2::VirtualMethod;
	void (SampleClassExtend2::*fptr_ex2_2)() = &SampleClassExtend2::VirtualMethod2;
	cout << "没有覆盖函数的子类的虚函数地址:" << endl;
	cout << reinterpret_cast<void*>(sce2.*fptr_ex2_1) << endl;
	cout << reinterpret_cast<void*>(sce2.*fptr_ex2_2) << endl;
    return 0;
}

/*
从上面的代码运行结果可以看出，若子类没有覆盖父类的虚函数，其虚函数地址和父类是相同的
若子类覆盖了任何父类的虚函数，则那一个虚函数的地址变为新的地址，其它虚函数仍和父类相同
此外，此程序无法使用MSVC编译，具体来说是MSVC不允许获取绑定函数的地址（指向绑定函数的指针只能
用于调用函数）
*/