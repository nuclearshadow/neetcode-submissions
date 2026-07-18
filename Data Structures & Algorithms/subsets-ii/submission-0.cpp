class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        rec(nums, 0, {}, res);
        return res;
    }

    void rec(vector<int>& nums, int i, vector<int> subset, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        auto included = subset;
        included.push_back(nums[i]);
        rec(nums, i+1, included, res);
        auto j = i;
        while (j < nums.size() && nums[i] == nums[j]) j++;
        rec(nums, j, subset, res);
    }
};
