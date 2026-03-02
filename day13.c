// Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

// Input:
// - First line: integer n representing number of rows and columns
// - Next n lines: n integers each representing the matrix elements

// Output:
// - Print "Identity Matrix" if the matrix satisfies the condition
// - Otherwise, print "Not an Identity Matrix"

// Example:
// Input:
// 3
// 1 0 0
// 0 1 0
// 0 0 1

// Output:
// Identity Matrix


#include <stdio.h>

int main(){
    int m,n;
    printf("Enter the no. of rows and no. of columns: ");
    scanf("%d %d", &m, &n);

    int mat[m][n];

    if(m!=n){
        printf("not valid matrix");
        return 0;
    }

    printf("Enter the elements matrix: ");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }


    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                if(mat[i][j]!=1){
                    printf("NOT IDENTITIY ");
                    return 0;
                }
            }

            else{
                if(mat[i][j] != 0){
                    printf("NOT IDENTITY");
                    return 0;
                }
            }
        }
    }

    
    printf("YES! SYMMETRIC");

    return 0;

}
