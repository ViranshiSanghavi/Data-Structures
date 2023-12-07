// Selection sort
#include<stdio.h>
#include<conio.h> 

int main() {
    int n, i, j, a[10], min, temp;
    printf("SELECTION SORT");
    printf("\nEnter how many elements\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[min] > a[j])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("The sorted elements are\n");
    for (i = 0; i < n; i++)
        printf("%d \n ", a[i]);
    getch();
}

/*SELECTION SORT

Enter how many elements: 6
Enter the elements:
5 2 9 1 5 6
*/
