#include <stdio.h>

void iterativeFibonacci(int n) {
    long long a = 0, b = 1, fib;
    printf("%lld ", a);
    if (n > 0) {
        printf("%lld ", b);
    }

    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
        printf("%lld ", fib);
    }
    printf("\n");
}

int main() {
    int number;
    printf("Enter the number of terms in Fibonacci sequence: ");
    scanf("%d", &number);

    iterativeFibonacci(number - 1); 

    return 0;
}
