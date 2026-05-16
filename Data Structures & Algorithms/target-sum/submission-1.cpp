class Solution {
public:
    map<tuple<int, int>, int> memo;
    int findTargetSumWays(vector<int>& nums, int target) {
        return rec(nums, target, 0, 0);
    }

    int rec(vector<int>& nums, int target, int i, int sum) {
        if (i >= nums.size()) {
            if (sum == target) return 1;
            return 0;
        }
        if (memo.contains({i, sum})) {
            return memo[{i, sum}];
        }
        return memo[{i, sum}] = rec(nums, target, i+1, sum + nums[i]) 
            + rec(nums, target, i+1, sum - nums[i]);
    }
};
