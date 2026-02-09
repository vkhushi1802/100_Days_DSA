// Problem: Given integers a and b, compute a^b using recursion without using pow() function.

// Input:
// - Two space-separated integers a and b

// Output:
// - Print a raised to power b

// Example:
// Input:
// 2 5

// Output:
// 32

// Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32


#include <stdio.h>

int power(int base, int pow){
    if(pow<0) return 0;

    if(pow == 0) return 1;

    return base*power(base, pow-1);
}

int main(){
    int base;
    printf("Enter the base value:: ");
    scanf("%d", &base);

    int pow;
    printf("Enter the power value:: ");
    scanf("%d", &pow);

    int ans;
    ans = power(base, pow);
    printf("%d", ans);

    return 0;

}