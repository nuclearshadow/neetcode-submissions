class Solution {
public:
    const char sep = ',';
    const char esc = '~'; 

    string encode(vector<string>& strs) {
        string s;
        for (const auto& str : strs) {
            for (char c : str) {
                if (c == sep || c == esc) {
                    s.push_back(esc);
                }
                s.push_back(c);
            }
            s.push_back(sep);
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string current;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == sep) {
                res.push_back(current);
                current = "";
                continue;
            }
            if (c == esc) {
                c = s[++i];
            }
            current.push_back(c);
        }
        return res;
    }
};
