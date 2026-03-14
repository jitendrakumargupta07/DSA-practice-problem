class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int buy = -1;

        for(int i = 0; i < prices.size(); i++) {
            if (i == prices.size() - 1) {
                if (buy != -1) {
                    ret += prices[i] - buy;
                    buy = -1;
                }
            } else {
                if (prices[i] < prices[i + 1]) {
                    if (buy == -1)
                        buy = prices[i];
                } else {
                    if (buy != -1) {
                        ret += prices[i] - buy;
                        buy = -1;
                    }
                }
            }
        }

        return ret;
    }
};