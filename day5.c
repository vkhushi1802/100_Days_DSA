// Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

// Input:
// - First line: integer p (number of entries in server log 1)
// - Second line: p sorted integers representing arrival times from server 1
// - Third line: integer q (number of entries in server log 2)
// - Fourth line: q sorted integers representing arrival times from server 2)

// Output:
// - Print a single line containing all arrival times in chronological order, separated by spaces

// Example:
// Input:
// 5
// 10 20 30 50 70
// 4
// 15 25 40 60

// Output:
// 10 15 20 25 30 40 50 60 70

// Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed



#include <stdio.h>

void merge(int p, int q, int arr1[], int arr2[]){
    int arr[p+q];
    int i=0, j=0,k=0;


    while(i<p && j<q){
        if(arr1[i]<arr2[j]){
            arr[k++] = arr1[i++];
        }
        else{
            arr[k++] = arr2[j++];
        }
    }

    while(i<p){
        arr[k++] = arr1[i++];
    }

    while(j<q){
        arr[k++] = arr2[j++];
    }


    for (int x = 0; x < p + q; x++) {
        printf("%d ", arr[x]);
    }
}




int main(){
    int p=5;
    int arr1[]= {10,20,30,50,70};
    int q=4;
    int arr2[]= {15, 25, 40, 60};

    merge(p,q,arr1, arr2);

    return 0;
}