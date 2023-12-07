#include<stdio.h>
#include<conio.h>
int a[20],b[20],c[20];
int n,i,pos,val,temp,m,j,p;
int choice;
int main()
{
    printf("\nEnter the number of elements of first array\n");
    scanf("%d",&n);
    printf("\nEnter the elements of the first array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
   printf("\nEnter the number of elements of second array\n");
    scanf("%d",&m);
    printf("\nEnter the elements of the second array:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    printf("\nThe elements of the first array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nThe elements of the second array\n");
    for(i=0;i<m;i++)
    {
        printf("%d\t",b[i]);
    }
    for(i=0;i<n;i++)
        {
                c[i]=a[i];
                //j=i+1;
        }
        for(j=0;j<m;i++,j++)
        {
                c[i]=b[j];
        }
        p=n+m;
        printf("\nArray elements of the array after merging:\n");
        for(i=0;i<p;i++)
        {
                printf("%d\t",c[i]);
        }
        for(i=0;i<p;i++)
	    {
	        for(j=i+1;j<p;j++)
	        {
	            if(c[i]>c[j])
	            {
	            temp=c[i];
	            c[i]=c[j];
	            c[j]=temp;
	            }
	        }
	    }
	    printf("\nArray elements of the array after sorting:\n");
        for(i=0;i<p;i++)
        {
                printf("%d\t",c[i]);
        }
    }

 
 /*Enter the number of elements of first array
3

Enter the elements of the first array:
10
20
30

Enter the number of elements of second array
3

Enter the elements of the second array:
5
15
25

The elements of the first array
10  20  30  
The elements of the second array
5  15  25  
Array elements of the array after merging:
10  20  30  5  15  25  
Array elements of the array after sorting:
5  10  15  20  25  30
*/
