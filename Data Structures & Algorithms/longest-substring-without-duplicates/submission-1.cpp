class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> lastIdx;
        int start = 0, maxL = 0;
        for (int i = 0; i < s.size(); i++) {
            if (lastIdx.contains(s[i])) {
                start = max(start, lastIdx[s[i]] + 1);
            }
            lastIdx[s[i]] = i;
            maxL = max(maxL, i - start + 1);
        }
        return maxL;
    }
};
