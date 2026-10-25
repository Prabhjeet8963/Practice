#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p = 8;

    if (p >= n || p < 0) {
        printf("Invalid position!\n");
        return 1;
    }
    for (int i = p; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("new array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
