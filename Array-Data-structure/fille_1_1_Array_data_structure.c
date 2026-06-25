#include <stdio.h>


//**** Array is a fixed size sequenced collection of data items of same data type

//**** We can access a particular element using: arrayname[index]

//**** Data items are stored in continuos locations

//**** Random access complexity is constant time O(1)




//***** Declare size of array at Compile time
// 1. Array size can't be changed



int main(void){
    
    int a[5] = {1,1};

    for(int i = 0; i < 5; i++){
        if(i <= 3){
            printf("%d,", a[i]);
        }
        else{
            printf("%d", a[i]);
        }
    }
    // terminal: 1,1,0,0,0

    for(int j = 0; j < 5; j++){
        if(j <= 3){
            printf("%p,", &a[j]);
        }
        else{
            printf("%p\n", &a[j]);
        }
        // terminal: 0000000E6D21FF800,000000E6D21FF804,000000E6D21FF808,000000E6D21FF80C,000000E6D21FF810 
        /* Decimal conversion: 0xE6D21FF800 = 990,898,960,384
                0xE6D21FF804 = 990,898,960,388
                0xE6D21FF808 = 990,898,960,392
                0xE6D21FF80C = 990,898,960,396
                0xE6D21FF810 = 990,898,960,400
        */ 
    }





// *****Define functional array size at runtime with user input
// 1. Array size can't exceed memory allocation at compile time
// 2. Developer has to handle the overflow condition, so that it does not happen.

    int b[20];

    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);
    
    if(size <= 20){
        for(int k = 0; k < size; k++){       
            printf("Element%d:", (k+1));
            scanf("%d", &b[k]);
        }
        
        printf("{");
        for(int l = 0; l < size; l++){
            if(l < size -1){
            printf("%d,", b[l]);
        }
        else{
            printf("%d}", b[l]);
        }
    }
    }
    else{
        printf("Overflow condition, size can't be greater than 20");
    }
    
    
    return 0;
}






