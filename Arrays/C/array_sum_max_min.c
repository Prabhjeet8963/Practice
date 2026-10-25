//Create an array of size 20 and display it!

//Find the sum of all the previous array

//Create an array of size 20 and display it
//Find the sum of all the previous array
#include <stdio.h>
int main() {
    int arr[20];
    int sum=0;
    int max,min;
    for (int i = 0; i < 20; i++) {
        printf("Enter element %d  ",i+1);
        scanf("%d",&arr[i]);
    }
    max = min = arr[0];
    for (int i = 1; i < 20; i++) {
        if (arr[i] > max) 
        {
            max = arr[i];
        } 
        if (arr[i] < min) 
        { 
            min = arr[i]; 
        }
        }
    printf("\nThe largest element in the array is: %d\n", max); 
    printf("The smallest element in the array is: %d\n", min);
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
        sum+=arr[i];
    }
    printf("%d",sum);
return 0;
}

