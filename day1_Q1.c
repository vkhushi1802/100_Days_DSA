// Insert an Element in an Array

// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (the array)
// - Third line: integer pos (1-based position)
// - Fourth line: integer x (element to insert)

// Output:
// - Print the updated array (n+1 integers) in a single line, space-separated

// Example:
// Input:
// 5
// 1 2 4 5 6
// 3
// 3

// Output:
// 1 2 3 4 5 6

// Explanation: Insert 3 at position 3, elements [4,5,6] shift right


#include <stdio.h>

void insert(int arr[], int *n, int idx, int num){

    idx = idx-1;
    (*n)++;
    for(int i=*n-1; i>idx; i--){
        arr[i]=arr[i-1];
    }

    arr[idx]=num;

    for(int i=0; i<*n; i++){
        printf("%d ", arr[i]);
    }

}

int main(){
    int n;
    printf("Enter the Size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int idx;
    printf("Enter 1-based position of element: ");
    scanf("%d", &idx);

    int num;
    printf("Enter the element: ");
    scanf("%d", &num);

    insert(arr, &n, idx, num);

    return 0;
}