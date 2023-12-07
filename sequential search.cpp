#include <stdio.h>

int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; // Element found, return its index
    }

    return -1; // Element not found
}

int main() {
    int n, target;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    int result = sequentialSearch(arr, n, target);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in the array\n", target);

    return 0;
}


/*Enter the size of the array: 5
Enter 5 array elements:
10
20
30
40
50
Enter the target element: 30
Element 30 found at index 2
*/
