class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        rec(nums, target, {}, 0, 0, res);
        return res;
    }

    void rec(vector<int>& nums, int target, vector<int> comps, int sum, int i, vector<vector<int>>& res) {
        if (i >= nums.size()) return;

        int next = i+1;
        while (next < nums.size() && nums[i] == nums[next]) {
            next++;
        }

        rec(nums, target, comps, sum, next, res);
        int newsum = sum + nums[i];
        auto included = comps;
        included.push_back(nums[i]);
        if (newsum == target) {
            res.push_back(included);
            return;
        } else if (newsum > target) {
            return;
        }
        rec(nums, target, included, newsum, i+1, res);
    }
};
