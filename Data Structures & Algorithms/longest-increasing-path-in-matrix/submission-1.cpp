class Solution {
public:
    vector<vector<int>> memo;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memo = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
        int longest = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                longest = max(longest, rec(matrix, i, j));
            }
        }
        return longest;
    }

    int rec(vector<vector<int>>& matrix, int i, int j) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int longest = 0;
        if (i + 1 < matrix.size() && matrix[i][j] < matrix[i+1][j]) {
            longest = max(longest, rec(matrix, i+1, j));
        }
        if (i - 1 >= 0 && matrix[i][j] < matrix[i-1][j]) {
            longest = max(longest, rec(matrix, i-1, j));
        }
        if (j + 1 < matrix[0].size() && matrix[i][j] < matrix[i][j+1]) {
            longest = max(longest, rec(matrix, i, j+1));
        }
        if (j - 1 >= 0 && matrix[i][j] < matrix[i][j-1]) {
            longest = max(longest, rec(matrix, i, j-1));
        }
        return memo[i][j] = longest + 1;
    }
};
