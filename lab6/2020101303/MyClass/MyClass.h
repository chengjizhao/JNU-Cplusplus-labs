#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass
{
    private:
        void Private_MemberFunc();
        friend class FriendClass;
    public:
        void Call_Private_MemberFunc();
};
#endif