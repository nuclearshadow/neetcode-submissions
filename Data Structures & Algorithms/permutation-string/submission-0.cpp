class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        map<char, int> f;

        for (char c : s1)
            f[c]++;

        for (int i = 0; i <= s2.size() - s1.size(); i++) {
            map<char, int> fc = f;
            bool ok = true;

            for (int j = i; j < i + s1.size(); j++) {
                fc[s2[j]]--;

                if (fc[s2[j]] < 0) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return true;
        }

        return false;
    }
};