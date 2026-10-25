// large,small,sum,average

#include <stdio.h>

int main() {
    int arr[100], n = 0, i, choice;
    int largest, smallest, sum;
    float average;
    int isArrayInitialized = 0;

    do {
        printf("\n===== Array Operations Menu =====\n");
        printf("1. Accept n integers and store in array\n");
        printf("2. Display array elements\n");
        printf("3. Find largest, smallest, sum, and average\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Accept array input
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                if(n <= 0 || n > 100) {
                    printf("Invalid number of elements.\n");
                    n = 0; // Reset n
                } else {
                    printf("Enter %d integers:\n", n);
                    for(i = 0; i < n; i++) {
                        printf("Element %d: ", i + 1);
                        scanf("%d", &arr[i]);
                    }
                    isArrayInitialized = 1;
                    printf("Array input successful!\n");
                }
            break;

            case 2:
                // Display array
                if(!isArrayInitialized) {
                    printf("Array not initialized! Please enter elements first.\n");
                } else {
                    printf("The array elements are:\n");
                    for(i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                // Find largest, smallest, sum, average
                if(!isArrayInitialized) {
                    printf("Array not initialized! Please enter elements first.\n");
                } else {
                    largest = smallest = arr[0];
                    sum = 0;
                    for(i = 0; i < n; i++) {
                        if(arr[i] > largest)
                            largest = arr[i];
                        if(arr[i] < smallest)
                            smallest = arr[i];
                        sum += arr[i];
                    }
                    average = (float)sum / n;
                    printf("Largest element: %d\n", largest);
                    printf("Smallest element: %d\n", smallest);
                    printf("Sum of all elements: %d\n", sum);
                    printf("Average of all elements: %.2f\n", average);
                }
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    } while(choice != 4);

    return 0;
}
