#include <stdio.h>
#include <math.h>

void printAP(int a, int d, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a + i * d);
    }
    printf("\n");
}

void printGP(int a, int r, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a * (int)pow(r, i));
    }
    printf("\n");
}
int main() {
    int a, d, r, n;

    printf("Enter the first term: ");
    scanf("%d", &a);
    printf("Enter the common difference for AP common ratio for GP: ");
    scanf("%d", &d);
    printf("Enter the common ratio for GP: ");
    scanf("%d", &r);
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printAP(a, d, n);
    printGP(a, r, n);
    return 0;
}