#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int lenth = prices.size();
        for (int i = 0; i < lenth - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                res += prices[i + 1] - prices[i];
            }
        }

        return res;
    }
};


