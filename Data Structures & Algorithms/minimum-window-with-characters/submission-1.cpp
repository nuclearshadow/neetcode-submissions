class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        string minW = "";
        int minL = INT_MAX;
        map<char, int> tf;
        for (auto c : t) {
            tf[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (!tf.contains(s[i])) {
                continue;
            }
            auto wf = tf;
            for (int j = i; j < s.size(); j++) {
                if (!tf.contains(s[i])) {
                    continue;
                }
                wf[s[j]]--;
                bool all = true;
                for (auto [c, f] : wf) {
                    if (f > 0) all = false;
                }
                if (all && minL > j-i+1) {
                    minW = s.substr(i, j-i+1);
                    minL = minW.size();
                }
            }
        }
        return minW;
    }
};
