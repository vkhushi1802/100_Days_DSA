// Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

// Input:
// - First line: two integers r and c representing the number of rows and columns
// - Next r lines: c integers each representing the matrix elements

// Output:
// - Print all visited elements in the order of traversal, separated by spaces

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 1 2 3 6 9 8 7 4 5

// Explanation:
// The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

// Test Cases:

// Test Case 1:
// Input:
// 2 3
// 1 2 3
// 4 5 6
// Output:
// 1 2 3 6 5 4

// Test Case 2:
// Input:
// 3 1
// 7
// 8
// 9
// Output:
// 7 8 9





#include <stdio.h>

int main(){
    int m,n;
    printf("Enter the no. of rows and no. of columns: ");
    scanf("%d %d", &m, &n);

    int mat[m][n];


    printf("Enter the elements matrix: ");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }



    int st_row =0;
    int st_col = 0;
    int end_row = m-1;
    int end_col = n-1;

    while(st_row<=end_row && st_col <= end_col){
        for(int i=st_col; i<=end_col; i++){
            printf("%d ", mat[st_row][i]);
        }
        st_row++;

        for(int i=st_row; i<=end_row; i++){
            printf("%d ", mat[i][end_col]);

        }
        end_col--;

        if(st_row<=end_row){
            for(int i=end_col; i>=st_col; i--){
                printf("%d ", mat[end_row][i]);
            }
            end_row--;

        }
        
        if(st_col <= end_col){
            for(int i=end_row; i>=st_row; i--){
                printf("%d ", mat[i][st_col]);
            }
            st_col++;
        }

        
    }


    return 0;

}

