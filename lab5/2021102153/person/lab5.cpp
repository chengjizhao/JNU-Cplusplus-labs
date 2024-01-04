#include"person.cpp"
int main()
{   
    person a;//方式1
    person b("理想",987654,"2002年7月21日","男",181,70);//方式2
    person c(b);//方式3
    a.getBirthday("2003年5月20日");
    a.getName("来实");
    a.getID(123456789);
    a.getGender("男");
    a.getWeight(56);
    a.getHeight(170);
    a.show();
    cout << "内存大小为" << sizeof(a) << endl;
    b.show();
    cout << "内存大小为" << sizeof(b) << endl;
    c.show();
    cout << "内存大小为" << sizeof(c) << endl;
    // 对象占120个字节其中名字和性别和生日为string类，所占为32个字节，身份和身高和体重本身所占字节为4，函数不占字节，根据内存对齐原则，以及声明数据成员的顺序可知身份和身高和体重所占字节数应补齐为8；因此总字节数为32*3+8*3=120
}