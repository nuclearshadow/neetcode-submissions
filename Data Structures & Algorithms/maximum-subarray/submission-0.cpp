class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};
