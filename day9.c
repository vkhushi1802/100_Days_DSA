// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards

#include <stdio.h>
#include <string.h>
#define MAX 100


void check_palindrome(char *str){
    if(str==NULL){
        printf("NULL");
        return;

    } 

    int i=0;
    int j=strlen(str)-1;
    while(i<j){
        if(str[i] != str[j]) {
            printf("NO");
            return;
        }
        i++;
        j--;  
    }

    printf("YES");


}


int main(){
    char str[MAX];

    printf("Enter the string: ");
    scanf("%s", str);

    check_palindrome(str);

    return 0;
}