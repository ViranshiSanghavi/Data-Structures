// INSERTION SORT
#include <stdio.h>

int main() {
    int a[100], n, i, val, curr, temp;
    printf("INSERTION SORT");
    printf("\nEnter the total length of elements: ");
    scanf("%d", &n);

    printf("\nEnter the Array Elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i < n; i++) {
        val = a[i];
        curr = i;
        while (a[curr - 1] > val && curr != 0) {
            a[curr] = a[curr - 1];
            curr = curr - 1;
        }
        a[curr] = val;
    }

    printf("\nInsertion Sort Result: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}

/*INSERTION SORT

Enter the total length of elements: 6

Enter the Array Elements:
5 2 9 1 5 6
*/
