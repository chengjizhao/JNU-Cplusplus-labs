#include "header.h"


void cIPprocessor::data_Process()
{
    auto head   = cIPprocessor::buffer.begin();
    auto tail   = cIPprocessor::buffer.end();
    int length  = cIPprocessor::buffer.size();
    
    if(length != 0)
    {
        int nCarry;
        int nMove;
        nCarry = buffer[0];

        nVersion    =  nCarry & 0x0F;
        nHeadlength = (nCarry >> 4) & 0x0F;
        nPriority   = (nCarry >> 8) & 0xFF;
        nLength     = (nCarry >> 16)& 0xFFFF;

        nCarry = buffer[1];
        nIdentifier =  nCarry & 0xFFFF;
        nFlag       = (nCarry >> 16) & 0x07;
        nOffset     = (nCarry >> 19) & 0x1FFF;

        nCarry = buffer[2];
        nTTL        =  nCarry & 0xFF;
        nPortNum    = (nCarry >> 8) & 0xFF;
        nChecksum   = (nCarry >> 16) & 0xFFFF;

        nSourseAdr = buffer[3];
        nTargetAdr = buffer[4];

        for(int i=0; i<length-5; i++)
        {
            aData[i] = buffer[i+5];
        }
    }
}
