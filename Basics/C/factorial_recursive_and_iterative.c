// Write a C program to create a function for n! using recursion and without recursion
#include <stdio.h>

// Function to calculate factorial using recursion
long long factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: 0! = 1 and 1! = 1
    } else {
        return n * factorial_recursive(n - 1); // Recursive call
    }
}

// Function to calculate factorial without recursion (iteratively)
long long factorial_iterative(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i; // Multiply result with current number
    }
    return result;
}

int main() {
    int n;

    // Input from user
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);

    // Calculating factorial using recursion
    long long fact_recursive = factorial_recursive(n);
    printf("Factorial of %d using recursion is: %lld\n", n, fact_recursive);

    // Calculating factorial without recursion (iteratively)
    long long fact_iterative = factorial_iterative(n);
    printf("Factorial of %d without recursion is: %lld\n", n, fact_iterative);

    return 0;
}
/*Input: Enter a number to calculate its factorial: 5
Output: Factorial of 5 using recursion is: 120
Factorial of 5 without recursion is: 120*/
