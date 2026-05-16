class Solution {
public:
    map<tuple<int, bool>, int> mem;

    int maxProfit(vector<int>& prices) {
        return maxRec(prices, 0, true);
    }

    int maxRec(vector<int>& prices, int i, bool canBuy) {
        if (i >= prices.size()) {
            return 0;
        }
        if (mem.contains({i, canBuy})) {
            return mem[{i, canBuy}];
        }
        return mem[{i, canBuy}] = max(maxRec(prices, i+1, canBuy), 
            canBuy
            ? maxRec(prices, i+1, false) - prices[i]
            : maxRec(prices, i+2, true) + prices[i]);
    }
};
