#include "Lyn_han.h"

char out[2048]={0,};
char * Con2U8(char* _szText)
{
    USES_CONVERSION;
    ZeroMemory(out,2048);
    wchar_t *wc = A2W(_szText);
    WideCharToMultiByte(CP_UTF8,0,wc,-1,out,2048,0,0);
    return out;
}