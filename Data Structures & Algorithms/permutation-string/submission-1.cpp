class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        int f[26] = {0};
        for (auto c : s1) {
            f[c-'a']++;
        }
        int rf[26] = {0};
        for (int i = 0; i < s1.size(); i++) {
            rf[s2[i]-'a']++;
        }
        for (int i = 0; i <= s2.size() - s1.size(); i++) {
            bool match = true;
            for (int j = 0; j < 26; j++) {
                if (f[j] != rf[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
            rf[s2[i]-'a']--;
            rf[s2[i+s1.size()]-'a']++;
        }
        return false;
    }
};
