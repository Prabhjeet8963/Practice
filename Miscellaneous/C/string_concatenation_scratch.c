#include <stdio.h>
#include <string.h>

int main() 
{
    char a[100] = "world";
    char b[20] = "hello";
    
    strcat(a,b);
    printf("the number is %s\n",a);
    return 0;

}