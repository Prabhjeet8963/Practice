//Write a C program to delete the element at a given 
//1-based position pos from an array of n integers.

int main() {
    
    int n, pos;
    scanf("%d", &n);
    int arr[n];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position
    scanf("%d", &pos);

    // Shift elements to the left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print updated array
    for (int i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);

        if (i < n - 2) {
            printf(" ");
        }
    }

    return 0;
}