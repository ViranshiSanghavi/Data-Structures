#include <stdio.h>

int n, val;
int a[5];

int seq_search();

int main() {
    printf("\n SEQUENTIAL SEARCH\n");
    printf("\n Enter five elements : ");
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("\n Enter value to search : ");
    scanf("%d", &val);
    
    seq_search();
}

int seq_search() {
    int chk = 0;
    
    for (int i = 0; i < 5; i++) {
        if (val == a[i]) {
            printf("\n Value is found at %d", i + 1);
            chk = 1;
            return 0;
        }
    }
    
    if (chk == 0) {
        printf("\n Value is not found ");
    }
}

/*SEQUENTIAL SEARCH

Enter five elements : 10 20 30 40 50

Enter value to search : 30
*/
