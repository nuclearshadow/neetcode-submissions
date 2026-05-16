class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size()));
        cout << "  ";
        dp[0][0] = text1[0] == text2[0] ? 1 : 0;
        cout << text2[0];
        for (int i = 1; i < text1.size(); i++) {
            dp[i][0] = max(dp[i-1][0], text1[i] == text2[0] ? 1 : 0);
        }
        for (int i = 1; i < text2.size(); i++) {
            dp[0][i] = max(dp[0][i-1], text1[0] == text2[i] ? 1 : 0);
            cout << " " << text2[i];
        }
        cout << endl;
        cout << text1[0];
        for (int i = 0; i < dp[0].size(); i++) {
            cout << " " << dp[0][i];
        }
        cout << endl;
        for (int i = 1; i < text1.size(); i++) {
            cout << text1[i] << " " << dp[i][0];
            for (int j = 1; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                cout << " " << dp[i][j];
            }
            cout << endl;
        }
        return dp[text1.size() - 1][text2.size() - 1];
    }
};
