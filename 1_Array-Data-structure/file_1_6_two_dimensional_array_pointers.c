#include <stdio.h>

int main(void){

    int a[3][3] = {{4,8,7},{5,6,9},{7,5,3}};
    
    int *p;

    // p = a;
    // printf("%u", p);
    /*
        terminal: error: assignment to 'int *' from incompatible pointer type 'int (*)[3]
    */

    // p = &a;
    // printf("%d", p);
    /*
        terminal: error: assignment to 'int *' from incompatible pointer type 'int (*)[3][3]'
    */

    // p = &a[0];
    // printf("%u", p);
    /*
        terminal: error: assignment to 'int *' from incompatible pointer type 'int (*)[3]'
    */

    p = a[0];
    printf("%u\n", p);

    // terminal: 2514482800
    
    p = &a[0][0];
    printf("%u\n", p);
    
    // terminal: 2514482800

    printf("%u %u %u %u %u\n", a, &a, a[0], &a[0], &a[0][0]);    
    // terminal: 1134557984 1134557984 1134557984 1134557984 1134557984
    
    
    // POINTER ARITHMETIC
    
    printf("address of a: %u and address of a + 1: %u\n", a, a + 1);
    // terminal: address of a: 4238342208 and address of a + 1: 4238342220

    printf("address of &a: %u and address of &a + 1: %u\n", &a, &a + 1);
    // terminal: address of &a: 2870998848 and address of &a + 1: 2870998884
    
    printf("address of a[0]: %u and address of a[0] + 1: %u\n", a[0], a[0] + 1);
    // terminal: address of a[0]: 1377827600 and address of a[0] + 1: 1377827604

    printf("address of &a[0]: %u and address of &a[0] + 2: %u\n", &a[0], &a[0] + 2);
    // terminal: address of &a[0]: 3651140768 and address of &a[0] + 2: 3651140792


    /*
      1. a[2][1] = *(a[2] + 1) = *(*(a + 2) + 1)
      2. Formula = B + ((i * n) + j)) * sizeof(int)
    */
    

    int c[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &c[i][j]);
        }
    }
    
    for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
            printf("%d", *(*(c+k)+l));
        }
    }

    

    return 0;
}