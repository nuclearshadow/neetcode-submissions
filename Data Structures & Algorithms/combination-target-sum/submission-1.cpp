class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        rec(nums, target, {}, 0, 0, res);
        return res;
    }

    void rec(vector<int>& nums, int target, vector<int> comps, int sum, int i, vector<vector<int>>& res) {
        if (i >= nums.size()) return;
        rec(nums, target, comps, sum, i+1, res);
        int newsum = sum + nums[i];
        auto included = comps;
        included.push_back(nums[i]);
        if (newsum == target) {
            res.push_back(included);
            return;
        } else if (newsum > target) {
            return;
        }
        rec(nums, target, included, newsum, i, res);
    }
};
