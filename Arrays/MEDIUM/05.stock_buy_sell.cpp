#include<bits/stdc++.h>
using namespace std;

/*
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0
*/

int maxProfit(vector<int> prices){
    int minPrice = INT_MAX;
    int profit = 0;

    for(int i=0; i<prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        profit = max(profit, prices[i] - minPrice);
    }
    
    return profit;
}


int main(){
    vector<int> prices = {3, 1, 5, 6, 2, 12};
    //  vector<int> prices = {7,6,4,3,1};
    cout << maxProfit(prices) << endl;
}
