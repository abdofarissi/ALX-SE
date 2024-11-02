#include <stdio.h>

int main()
{
    char i;

    for(i = 48; i < 58; i++)
    {
        putchar(i);   
    }
    char j;
    for(j = 97;j <= 102;j++ )
    {
        putchar(j);
    }
        putchar('\n');

    return 0;
}