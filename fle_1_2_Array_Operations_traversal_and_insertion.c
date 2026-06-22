
#include <stdio.h>


//*** Traversal of array elements

// int main(void){
    

//     int a[50];
//     int size;

//     printf("Enter the size of array: ");
//     scanf("%d", &size);

//     if(size >= 0 && size <= 50){
//         printf("Enter elements of Array.\n");
//         for(int i = 0; i < size; i++){
//             printf("Element%d: ", i + 1);
//             scanf("%d", &a[i]);
//         }

//         printf("\n{");
        
//         for(int j = 0; j < size; j++){
//             if(j < size - 1){
//                 printf("%d,", a[j]);
//             }
//             else{
//                 printf("%d}\n",a[j]);
//             }
//         }

//         // Increase of 4 bytes for each position or index in array. For int value is of size 4 bytes. We can print increasing address using array traversal again.

//         for(int k = 0; k < size; k++){
//             printf("Element%d address is: %p\n", k+1, &a[k]);
//         }

//     }
//     else{
//         printf("Overflow condition, Size can't be greater than 50.");
//     }
//     // terminal: 
//     /*
//     Element1 address is: 00000053F0BFFA40
//     Element2 address is: 00000053F0BFFA44
//     Element3 address is: 00000053F0BFFA48
//     */

//     return 0;
// }



//******** Insertion in array


int main(void){
    
    int a[50];
    int size;
    int num;
    int pos;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    if(size <= 0 || size > 50){
        printf("Overflow condition. Size can't be lesser than 0 or greater than 50.");
    }

    else{
        printf("Enter elements of array.\n");
        for(int i = 0; i < size; i++){
            printf("Element%d: ", i + 1);
            scanf("%d", &a[i]);
        }

        printf("Your array is: {");
        for(int j = 0; j < size; j++){
            if(j < size - 1){
                printf("%d,", a[j]);
            }
            else{
                printf("%d}\n", a[j]);
            }
        }
    }

    printf("Enter the number you want to insert: ");
    scanf("%d", &num);

    printf("\nEnter the position you want to insert the number the number: ");
    scanf("%d", &pos);
    



    //Note: Time complexity of this code will be best case O(1) or worst case of O(n) or O(n-p), depending on the position of insertion. Last position will be time complexity O(1). 

    if(pos < 0 || pos > size){
        printf("Position of insertion for number can't be lesser than 0. also cant't be greater than size value you provided earlier");
    }
    else if(pos == 1){
        // If someone wants to inset the entry number to 1st position then the structure of our code will be different.

        for(int i = size - 1; i >= 0; i--){
            a[i+1] = a[i];
        }
        a[0] = num;
        size++;
    }

    else if(pos == size + 1){
        // This means if someone wants to insert a num right at the end of the array, then we don't need to traverse the array also. we can just put the value at size = index, means the last position of our new array, and increase size of array by 1.

        a[size] = num;
        size++;
    }

    else{

        // random position in array
        for(int i = size - 1; i >= pos - 1; i--){
            a[i+1] = a[i];
        }
        a[pos - 1] = num;
        size++;
    }

    printf("Your new array is: {");

    for(int j = 0; j < size; j++){
        if(j < size - 1){
            printf("%d,", a[j]);
        }
        else{
            printf("%d}", a[j]);
        }
    }
    

    // Note: Specially time complexity of a sorted array will be O(n), if we are inserting the number on a random position of n. For an unsorted array where the position does not matter we can insert number on the given position and delegate that positions current value to the end of array. This is the best algorithm for unsorted array and the time complexity will be O(1).

    // Here is the algo.

    // a[size] = a[pos - 1];
    // a[pos - 1] = num;
    // size++

    return 0;
}