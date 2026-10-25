#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    //Pseudo-Random= Apeear random but detrmined by formula that uses
    // Seed Value to generarte predectablie sequence of numbers
    
    // Seed the random number generator

    /* printf("%d", rand());
     Generate and print 5 pseudo-random numbers
    for (int i = 0; i < 5; i++) {
        int random_number = rand(); // Generate a pseudo-random number
        printf("Random Number %d: %d\n", i + 1, random_number);
    }*/


    srand(time(NULL)); // Fixed seed for reproducibility

    // printf("%d\n", rand()); this  will vary with time 

    // printf("%d\n", RAND_MAX);  the maximum possible value that the rand() function can return 

    int min = 50 ;
    int max = 100;
    int randomNum = (rand() % (max - min + 1)) + min ; 
    printf("Random Number (0 or 1): %d\n", randomNum);




    return 0;
}