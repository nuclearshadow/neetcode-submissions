class Solution {
public:
    vector<vector<int>> memo;

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        memo = vector<vector<int>>(
            s1.size() + 1,
            vector<int>(s2.size() + 1, -1)
        );

        return rec(s1, s2, s3, 0, 0);
    }

    bool rec(string& s1, string& s2, string& s3,
             int i, int j) {

        if (i + j == s3.size()) {
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        bool ans = false;

        if (i < s1.size() &&
            s1[i] == s3[i + j]) {

            ans |= rec(s1, s2, s3, i + 1, j);
        }

        if (j < s2.size() &&
            s2[j] == s3[i + j]) {

            ans |= rec(s1, s2, s3, i, j + 1);
        }

        return memo[i][j] = ans;
    }
};