#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[15][15],b[15][15],d[15][15],mul[15][15];
int i,j,k,r,c,r1,c1;
int ch=0;
void create(int row, int col,int x[15][15]);
void display(int row, int col,int x[15][15]);
void add(int row, int col, int x[15][15],int y[15][15]);
void multiply(int x[15][15],int y[15][15],int z[15][15]);
void transpose(int row, int col, int x[15][15]);
int main()
{
	do
	{
		printf("\nMenu\n");
        printf("1. Create\n");
        printf("2. Add\n");
        printf("3. Multiply\n");
        printf("4. Transpose\n");
        printf("5. Exit\n");
        printf("\n Enter your choice\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
					printf("\n\nEnter the number of rows in the matrix\n");
    				scanf("%d",&r); 
    				printf("\n\nEnter the number of columns in the matrix\n");
    				scanf("%d",&c);
    				create(r,c,a);
    				printf("\n\nMAtrix A\n\n");
    				display(r,c,a);
    				break;
    		case 2:
    				printf("\n\nEnter the number of rows in the new matrix\n");
    				scanf("%d",&r1); 
    				printf("\n\nEnter the number of columns in the new matrix\n");
    				scanf("%d",&c1);
    				create(r1,c1,b);
    				printf("\n\nMAtrix A\n\n");
    				display(r,c,a);
    				printf("\n\nMAtrix B\n\n");
    				display(r1,c1,b);
    				if(r==r1&&c==c1)
    				{
    					add(r,c,a,b);
					}
					else
					{
						printf("matrix cannot be added");
					}
					break;
			case 3:
					printf("\n\nEnter the number of rows in the new matrix\n");
    				scanf("%d",&r1); 
    				printf("\n\nEnter the number of columns in the new matrix\n");
    				scanf("%d",&c1);
    				create(r1,c1,b);
    				printf("\n\nMAtrix A\n\n");
    				display(r,c,a);
    				printf("\n\nMAtrix B\n\n");
    				display(r1,c1,b);
    				multiply(a,b,mul);
    				break;
    		case 4:
    				transpose(r,c,a);
    				break;
    		case 5: exit(0);
                    break;
            default: 
                    printf("\nInvalid Choice..\n");
                    break;
        }
        printf("\nDo you want to continue??\n\n1=Yes\n\n2=No\n");
        scanf("%d",&ch);
    }while(ch==1);
    return 0;
}

void create(int row, int col, int x[15][15])
{
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("\n Enter element at pos %d %d \t",i,j);
			scanf("%d",&x[i][j]);
		}
	}
}

void display(int row, int col, int x[15][15])
{
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",x[i][j]);
		}
		printf("\n");
	}
}

void add(int row, int col, int x[15][15],int y[15][15])
{
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			d[i][j]=x[i][j]+y[i][j];
		}
	}
	printf("\n\nMatrix after addition\n\n");
	display(row,col,d);
}

void multiply(int x[15][15],int y[15][15],int z[15][15])
{
	if(r1==c)
	for (i = 0; i < r; i++) 
	{
        for (j = 0; j < c; j++) 
		{
            z[i][j] = 0;
            for (k = 0; k < r1; k++)
                z[i][j] += x[i][k] * y[k][j];
        }
    }
    printf("\n\nMatrix after multiplication\n");
    display(r,c1,z);
}


void transpose(int row, int col, int x[15][15])
{
	printf("\n\nTranspose of the given matrix is\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",x[j][i]);
		}
		printf("\n");
	}
}

/*Menu
1. Create
2. Add
3. Multiply
4. Transpose
5. Exit

Enter your choice: 1

Enter the number of rows in the matrix: 2
Enter the number of columns in the matrix: 2

Enter element at pos 0 0: 1
Enter element at pos 0 1: 2
Enter element at pos 1 0: 3
Enter element at pos 1 1: 4

Matrix A

1       2
3       4

Do you want to continue?
1=Yes
2=No
1

Menu
1. Create
2. Add
3. Multiply
4. Transpose
5. Exit

Enter your choice: 2

Enter the number of rows in the new matrix: 2
Enter the number of columns in the new matrix: 2

Enter element at pos 0 0: 5
Enter element at pos 0 1: 6
Enter element at pos 1 0: 7
Enter element at pos 1 1: 8

Matrix A

1       2
3       4

Matrix B

5       6
7       8

Matrix after addition

6       8
10      12

Do you want to continue?
1=Yes
2=No
1

Menu
1. Create
2. Add
3. Multiply
4. Transpose
5. Exit

Enter your choice: 3

Enter the number of rows in the new matrix: 2
Enter the number of columns in the new matrix: 2

Enter element at pos 0 0: 1
Enter element at pos 0 1: 2
Enter element at pos 1 0: 3
Enter element at pos 1 1: 4

Matrix A

1       2
3       4

Matrix B

1       2
3       4

Matrix after multiplication

7       10
15      22

Do you want to continue?
1=Yes
2=No
1

Menu
1. Create
2. Add
3. Multiply
4. Transpose
5. Exit

Enter your choice: 4

Transpose of the given matrix is
1       3
2       4

Do you want to continue?
1=Yes
2=No
2
*/
