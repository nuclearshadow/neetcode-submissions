class Solution {
public:
    vector<vector<int>> memo;

    int numDistinct(string s, string t) {
        memo = vector<vector<int>>(s.size(), vector<int>(t.size(), -1));
        return rec(s, t, 0, 0);
    }

    int rec(string& s, string& t, int i, int j) {
        if (j >= t.size()) {
            return 1;
        }
        if (i >= s.size()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (s[i] == t[j]) {
            return memo[i][j] = rec(s, t, i+1, j) + rec(s, t, i+1, j+1);
        }
        return memo[i][j] = rec(s, t, i+1, j);
    }
};
