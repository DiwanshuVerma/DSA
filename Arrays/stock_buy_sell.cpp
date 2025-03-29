#include <iostream>
using namespace std;

// given an array of prices of stocks, consider indexes as days, the idea is to return maximum profit after buying and selling a stock
// buying and selling a stock is neccesory, can't sell on same day and in previous days

int main() {
    int stocks[] = {22, 12, 55 , 6, 22 };
    int n = 5;

    int bestBuy = stocks[0];
    int maxProfit = 0;

    for(int i = 1; i<n; i++) {

        if(stocks[i] > bestBuy){
            maxProfit = max(maxProfit, stocks[i] - bestBuy);
        }
       bestBuy = min(bestBuy, stocks[i]);
    }
    cout << "max profit is: " << maxProfit;

}