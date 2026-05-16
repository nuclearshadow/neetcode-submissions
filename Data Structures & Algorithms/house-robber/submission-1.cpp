class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int dp[nums.size()];
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = dp[i-2] + nums[i];
            if (i-3 >= 0) {
                dp[i] = max(dp[i], dp[i-3] + nums[i]);
            }
        }
        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};
