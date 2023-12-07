#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return true; 
    }
    if (str[start] != str[end]) {
        return false; 
    }
    return isPalindrome(str, start + 1, end - 1);
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    int length = strlen(input);
    bool result = isPalindrome(input, 0, length - 1);
    if (result) {
        printf("Palindrome!\n");
    } else {
        printf("Not a palindrome!\n");
    }
    return 0;
}



//Enter a string: hello
//Not a palindrome! 

