
// Two Sum Problem

// Problem Statement:
// Write a C program to find whether there exist two distinct elements in an array whose sum is equal to a given target value.
// Input:
// First line contains an integer n — the number of elements in the array
// Second line contains n space-separated integers
// Third line contains an integer target — the required sum
// Output:
// Print "YES" if such a pair exists
// Otherwise, print "NO"

#include <stdio.h>

#define SIZE 20000
#define OFFSET 10000

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int sum;
    printf("Enter the targer sum: ");
    scanf("%d", &sum);


    int hash[SIZE] = {0};

    for(int i=0; i<n; i++){
        int complement = sum - arr[i];

        if(complement + OFFSET >= 0 && complement + OFFSET < SIZE && hash[complement + OFFSET]){
            printf("YES");
            return 0;
        }

        hash[arr[i] + OFFSET] = 1;
    }

    printf("NO");
    return 0; 

}
