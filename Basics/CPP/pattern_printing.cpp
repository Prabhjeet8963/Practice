#include <stdio.h>

int main() {
    int rows = 5; // You can adjust the number of rows as needed
    int num = 1;

    for (int i = 1; i <= rows; i++) {
        if (i % 2 == 0) {
            // For even rows, print in decreasing order
            for (int j = num + i - 1; j >= num; j--) {
                printf("%d ", j);
            }
        } else {
            // For odd rows, print in increasing order
            for (int j = num; j < num + i; j++) {
                printf("%d ", j);
            }
        }
        printf("\n");
        num += i;
    }

    return 0;
}



