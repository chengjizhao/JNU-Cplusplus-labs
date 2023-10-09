#ifndef __HEADER_H
#define __HEADER_H

#include <vector>

using namespace std;

class cIPprocessor
{
private:
    unsigned int nVersion   : 4;
    unsigned int nHeadlength: 4;
    unsigned int nPriority  : 8;
    unsigned int nLength    :16;

    unsigned int nIdentifier:16;
    unsigned int nFlag      : 3;
    unsigned int nOffset    :13;

    unsigned int nTTL       : 8;
    unsigned int nPortNum   : 8;
    unsigned int nChecksum  :16;

    unsigned int nSourseAdr :32;
    
    unsigned int nTargetAdr :32;

    unsigned int* aData;
public:
    unsigned int na : 8;
    vector<int> buffer;             //IP数据包缓冲存放区
    void data_Process(void);
};


#endif
