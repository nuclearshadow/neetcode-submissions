class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        map<char, int> freq;
        char maxFreq;
        int maxL = 0;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            if (freq[s[i]] > freq[maxFreq]) {
                maxFreq = s[i];
            }
            if (i - start + 1 > freq[maxFreq] + k) {
                freq[s[start]]--;
                start++;
            }
            maxL = max(maxL, i - start + 1);
        }
        return maxL;
    }
};
