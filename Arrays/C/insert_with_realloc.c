#include <stdio.h>
#include <stdlib.h>
int main() {
int *array, *ptr;
int n, i, position, value;
printf("Enter the number of elements: ");
scanf("%d", &n);
array = (int*)malloc(n * sizeof(int));
if (array == NULL) {
     printf("Memory allocation failed!\n");
        return 1;
   }
printf("Enter %d integers:\n", n);
for (i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &array[i]);
}
printf("\nEnter the position where you want to insert the new element (1-%d): ", n + 1);
scanf("%d", &position);
printf("Enter the value of the new element: ");
scanf("%d", &value);
ptr = (int*)realloc(array, (n + 1) * sizeof(int));
if (ptr == NULL) {
    printf("Memory reallocation failed!\n");
    free(array);
    return 1;
}
for (i = n; i >= position; i--) {
    ptr[i] = ptr[i - 1];
}
ptr[position - 1] = value;
printf("\nThe updated array is:\n");
for (i = 0; i <= n; i++) {
    printf("%d ", ptr[i]);
}
printf("\n");
free(ptr);
return 0;
}
