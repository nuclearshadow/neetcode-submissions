class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int, int>> seen;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (solve(board, word, i, j, 0, seen)) return true;
            }
        }
        return false;
    }

    bool solve(vector<vector<char>>& board, string& word, int i, int j, int current, set<pair<int, int>>& seen) {
        if (board[i][j] != word[current]) return false;
        if (current + 1 == word.size()) return true;
        seen.insert({i, j});
        if (i+1 < board.size() && !seen.contains({i + 1, j}) && solve(board, word, i + 1, j, current+1, seen)) return true;
        if (i > 0 && !seen.contains({i - 1, j}) && solve(board, word, i - 1, j, current+1, seen)) return true;
        if (j+1 < board[i].size() && !seen.contains({i, j + 1}) && solve(board, word, i, j + 1, current+1, seen)) return true;
        if (j > 0 && !seen.contains({i, j - 1}) && solve(board, word, i, j - 1, current+1, seen)) return true;
        seen.erase({i, j});
        return false;
    }
};
