// Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

// Input:
// - First line: two integers m and n representing the number of rows and columns
// - Next m lines: n integers each representing the elements of the matrix

// Output:
// - Print "Symmetric Matrix" if the given matrix is symmetric
// - Otherwise, print "Not a Symmetric Matrix"

// Example:
// Input:
// 3 3
// 1 2 3
// 2 4 5
// 3 5 6

// Output:
// Symmetric Matrix

// Explanation:
// The matrix is square (3 × 3) and for every i and j, element[i][j] = element[j][i].

// Test Cases:

// Test Case 1:
// Input:
// 2 2
// 1 2
// 2 1
// Output:
// Symmetric Matrix

// Test Case 2:
// Input:
// 3 3
// 1 0 1
// 2 3 4
// 1 4 5
// Output:
// Not a Symmetric Matrix

// Test Case 3:
// Input:
// 2 3
// 1 2 3
// 4 5 6
// Output:
// Not a Symmetric Matrix


#include <stdio.h>

int main(){
    int m,n;
    printf("Enter the no. of rows and no. of columns: ");
    scanf("%d %d", &m, &n);

    int mat[m][n];

    if(m != n){
        printf("Invalid matrix");
        return 0;
    }

    printf("Enter the elements matrix: ");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }


    /*NOTE:- 
Check only upper triangle (j = i + 1):

- Diagonal elements need not be checked.
- Lower triangle elements are mirror of upper triangle.
- Avoids duplicate comparisons.
- Improves efficiency.
*/


    for(int i=0; i<m; i++){                         
        for(int j=i+1; j<n; j++){
            if( mat[i][j] != mat[j][i]){
                printf("Not Symmetric");
                return 0;
            }
        }
    }

    printf("YES! SYMMETRIC");

    return 0;

}
