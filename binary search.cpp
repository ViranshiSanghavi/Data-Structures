#include<stdio.h>
#include<conio.h>
int main()
{
    int i, j, n, arr[100], search, first, last, middle, temp;
    printf("How many element you want to store in array ? ");
    scanf("%d", &n);
    printf("\nEnter %d array elements: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("\nEnter element to be search: ");
    scanf("%d", &search);
	
    // sorting given array using bubble sort
    for(i=0; i<(n-1); i++)
    {
        for(j=0; j<(n-i-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
	
    // sort array
    printf("\nNow the sorted Array is:\n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    // back to binary search
    first = 0;
    last = n-1;
    middle = (first+last)/2;
    while(first <= last)
    {
        if(arr[middle]<search)
            first = middle+1;
        else if(arr[middle]==search)
        {
            printf("\n\nThe number, %d found at Position %d", search, middle+1);
            break;
        }
        else
            last = middle-1;
        middle = (first+last)/2;
    }
    if(first>last)
        printf("\nThe number, %d is not found in given Array", search);
    getch();
    return 0;
}
