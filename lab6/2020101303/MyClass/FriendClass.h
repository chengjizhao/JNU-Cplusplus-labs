#include "MyClass.h"

class FriendClass 
{
    public:
        void Get_Private_MemberFunc(MyClass& obj) 
        {
            obj.Private_MemberFunc();
        }
};