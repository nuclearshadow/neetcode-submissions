class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minPrice = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            res = max(res, prices[i] - minPrice);
        }
        return res;
    }
};
