class Solution {
public:
    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        memo = vector<vector<int>>(coins.size(), vector<int>(amount, -1));
        return changeRec(amount, coins, 0, 0);
    }

    int changeRec(int amount, vector<int>& coins, int i, int cur) {
        if (cur > amount || i >= coins.size()) {
            return 0;
        }
        if (cur == amount) {
            return 1;
        }
        if (memo[i][cur] != -1) {
            return memo[i][cur];
        }
        return memo[i][cur] = changeRec(amount, coins, i + 1, cur) + 
            changeRec(amount, coins, i, cur + coins[i]);
    }
};
