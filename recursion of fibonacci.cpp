#include <stdio.h>
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
    } else {
        int result = fibonacci(n);
        printf("Fibonacci(%d) = %d\n", n, result);
    }
    return 0;
}


//Enter the value of n: 10
//Fibonacci(10) = 55
