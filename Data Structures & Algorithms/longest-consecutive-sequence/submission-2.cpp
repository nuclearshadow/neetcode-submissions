class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int longest = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (numset.contains(nums[i] - 1)) continue;
            int len = 0;
            while (numset.contains(nums[i] + len)) {
                len++;
            }
            if (len > longest) {
                longest = len;
            }
        }
        return longest;
    }
};
