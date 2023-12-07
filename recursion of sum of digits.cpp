#include <stdio.h>
int sumOfDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return num % 10 + sumOfDigits(num / 10);
}
int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Please enter a positive integer.\n");
    } else {
        int result = sumOfDigits(num);
        printf("Sum of digits: %d\n", result);
    }
    return 0;
}

//Enter a positive integer: 12345
//Sum of digits: 15

