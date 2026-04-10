class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> seen;
        // rows
        for (int i = 0; i < board.size(); i++) {
            seen.clear();
            for (int j = 0; j < board[i].size(); j++) {
                if (seen.contains(board[i][j])) return false;
                if (board[i][j] != '.') seen.insert(board[i][j]);
            }
        }

        // columns
        for (int j = 0; j < board[0].size(); j++) {
            seen.clear();
            for (int i = 0; i < board.size(); i++) {
                if (seen.contains(board[i][j])) return false;
                if (board[i][j] != '.') seen.insert(board[i][j]);
            }
        }

        // squares
        for (int si = 0; si < board.size(); si += 3) {
            for (int sj = 0; sj < board[si].size(); sj += 3) {
                seen.clear();
                for (int i = si; i < si + 3; i++) {
                    for (int j = sj; j < sj + 3; j++) {
                        if (seen.contains(board[i][j])) return false;
                        if (board[i][j] != '.') seen.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
