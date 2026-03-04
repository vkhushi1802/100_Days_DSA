// Problem: Given an array of integers, count the frequency of each distinct element and print the result.

// Input:
// - First line: integer n (size of array)
// - Second line: n integers

// Output:
// - Print each element followed by its frequency in the format element:count

// Example:
// Input:
// 5
// 1 2 2 3 1

// Output:
// 1:2 2:2 3:1


#include <stdio.h>


int main(){

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){

        int alreadycounted=0;
        for(int k=0; k<i; k++){
            if(arr[i]== arr[k]){
                alreadycounted =1;
                break;
            }
        }


        if(alreadycounted) continue;

        int count=0;
        for(int j=0; j<n; j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;

}