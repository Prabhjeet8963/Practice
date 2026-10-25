#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // 1. Greedy / One-Pass
    int maxProfitGreedy(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }


    // 2. Two Pointer
    int maxProfitTwoPointer(vector<int>& prices) {
        int buy = 0;
        int sell = 1;
        int maxProfit = 0;

        while (sell < prices.size()) {
            if (prices[sell] > prices[buy]) {
                maxProfit = max(maxProfit,
                                prices[sell] - prices[buy]);
            } else {
                buy = sell;
            }

            sell++;
        }

        return maxProfit;
    }


    // 3. Kadane's Algorithm
    int maxProfitKadane(vector<int>& prices) {
        int currentProfit = 0;
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int dailyChange = prices[i] - prices[i - 1];

            currentProfit += dailyChange;
            currentProfit = max(0, currentProfit);

            maxProfit = max(maxProfit, currentProfit);
        }

        return maxProfit;
    }


    // Select approach
    int maxProfit(vector<int>& prices) {

        int choice = 1;

        switch (choice) {

            case 1:
                // Greedy / One-Pass
                return maxProfitGreedy(prices);

            case 2:
                // Two Pointer
                return maxProfitTwoPointer(prices);

            case 3:
                // Kadane's Algorithm
                return maxProfitKadane(prices);

            default:
                return 0;
        }
    }
};