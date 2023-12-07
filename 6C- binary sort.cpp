#include <stdio.h>
int binarySearch(int array[], int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int n;
    printf("\n BINARY SEARCH \n");
    printf("\n Enter the length of array : ");
    scanf("%d", &n);
    int array[n];
    printf("\n Enter elements :");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int x;
    printf("\nEnter the element for search : ");
    scanf("%d", &x);
    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
        printf("\n Not found");
    else
        printf("\n Element is found at position %d", result + 1);
}

/*BINARY SEARCH

Enter the length of array: 7

Enter elements: 10 20 30 40 50 60 70

Enter the element for search: 40
*/
