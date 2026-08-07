class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string buf;
        solve(n, 0, 0, buf, res);
        return res;
    }

    void solve(int n, int open, int opened, string& buf, vector<string>& res) {
        if (buf.size() == n*2 && open == 0) {
            res.push_back(buf);
            return;
        }
        if (open > 0) {
            buf.push_back(')');
            solve(n, open - 1, opened, buf, res);
            buf.pop_back();
        }
        if (opened <= n) {
            buf.push_back('(');
            solve(n, open + 1, opened + 1, buf, res);
            buf.pop_back();
        }
    }
};
