// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int minprice = INT_MAX;
    int ans = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minprice) {
            minprice = prices[i];
        }

        if (prices[i] - minprice > ans) {
            ans = prices[i] - minprice;
        }
    }

    return ans;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(prices[0]);

    int profit = maxProfit(prices, size);
    printf("Maximum Profit: %d\n", profit);

    return 0;
}


