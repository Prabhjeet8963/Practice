#include <stdio.h>

void Birthday(char x[] , int y) //parameters
{
    printf("Happy Birthday to You!\n");
    printf("Happy Birthday to You!\n");
    printf("Happy Birthday Dear %s!\n",x);
    printf("You are %d years old!!\n",y);
}


int main(){
    
    char name[] = "Sidak"; // Argument passed to function
    int age = 21;      // Argument passed to function
    
    Birthday(name,age);


    return 0;
}