class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> sfreq, tfreq;
        for (char c : s) sfreq[c] += 1;
        for (char c : t) tfreq[c] += 1;
        if (sfreq.size() != tfreq.size()) return false;
        for (const auto& [c, freq] : sfreq) {
            if (freq != tfreq[c]) return false;
        }
        return true;
    }
};
