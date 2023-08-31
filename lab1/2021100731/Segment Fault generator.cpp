#include <stdio.h>
/*
Name :  Segment_Error1
Brief:  This Segment error is caused by operating a pointer whose address is 0x00
*/
void Segment_Error1()
{
    char *p = 0x00;
    *p = 0x00;
}

/*
Name :  Segment_Error2
Brief:  This Segment error is caused by memory over-running
*/
void Segment_Error2()
{
    char test[1];  
    printf("%c", test[1000000000]);  

}



int main()
{
    Segment_Error1();
    Segment_Error2();
    return 0;
}
