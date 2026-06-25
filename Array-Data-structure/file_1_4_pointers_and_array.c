#include <stdio.h>

int main(void){

    //****** pointer to integer
    
    int b = 10;

    int *p;
    p = &b;

    printf("address of b: %p\n", p);
    // terminal: address of b: 000000CE7B1FF88C

    printf("address of pointer p: %p\n", &p);
    // terminal: address of pointer p: 000000CE7B1FF880

    printf("Value at b with dereference operator: %d\n", *p);
    // terminal: Value at b with dereference operator: 10

    p++;
    printf("New address of p should increase by 4 bytes: %p\n", p);
    // terminal: New address of p should increase by 4 bytes: 000000CE7B1FF890



    //****** Pointer to Array

    int a[] = {1,2,3,4,5};

    int *q;
    q = a;
    printf("Base address of a, with q: %p / with a; %p / with &a: %p\n", q, a, &a);
    // terminal: Base address of a, with q: 00000070BF5FFDA0 / with a; 00000070BF5FFDA0 / with &a: 00000070BF5FFDA0
    
    // q++;
    // printf("%p\n", q);
    // terminal: 00000070BF5FFDA4

    // a++;
    // printf("%p", a);
    // terminal: error: lvalue required as increment operand 
    // 40 |     a++;

    printf("Address of q pointer itself is: %p\n", &q);
    // terminal: Address of q pointer itself is: 0000001B76BFF7E8
    
    // Notice:
    // q = &a;
    // printf("%p", q);
    
    /*
    terminal: error: assignment to 'int *' from incompatible pointer type   'int (*)[5]' [-Wincompatible-pointer-types]
            40 |     q = &a;
            |       ^
    */

    // Pointer arithmetic:

    printf("%p\n", &a[2]);
    printf("%p\n", (a + 2));
    printf("%p\n", (q + 2));
    /* 
    terminal: 0000004F427FF928
              0000005D339FFDF8
              0000004F427FF928 
    */

    printf("%d\n", a[3]);
    printf("%d\n", *(a + 3));
    printf("%d\n", 3[a]);
    
    printf("%d\n", *(q + 3));
    printf("%d\n", 3[q]);

    /* 
    terminal: 4
              4
              4
              4
              4 
    */

    printf("base address: %p\n", a);
    printf("base address + 1 shift with a + 1: %p\n", a + 1);
    printf("base address + 1 shift with &a + 1: %p\n", &a + 1);
    printf("base address + 1 shift with &a[0] + 1: %p\n", &a[0] + 1);

    /* 
      terminal: base address + 1 shift with a + 1: 00000056C81FFB74
                base address + 1 shift with &a + 1: 00000056C81FFB84
                base address + 1 shift with &a[0] + 1: 00000056C81FFB74
    */
     
    /*
        Notice that if we convert these addresses to decimal values:
            548,274,641,668
        	548,274,641,684
            548,274,641,668
            
        1. value for a + 1 increased by 4 bytes from the base           address       because a decays to a pointer to the first element of the array (type int *).

        2. value for &a + 1 increased by 20 bytes from the base address     because
        &a is a pointer to the entire array (type int (*)[5]). Adding 1
        advances by the size of the whole array: 5 ints × 4 bytes = 20 bytes.

        3. value for &a[0] + 1 increased by 4 bytes from the base address   because
        &a[0] is the address of the first element (type int *). Adding 1
        advances by the size of one int, so it points to a[1].  
    */


    // Traverse the array using pointers

    for(int i = 0; i < 5; i++){
        printf("%d", i[a]);
        printf("%d", *(a + i));
        printf("%d", *(q + i));
        printf("%d", i[q]);
    }

    // terminal: 11112222333344445555
     
    
    return 0;
}