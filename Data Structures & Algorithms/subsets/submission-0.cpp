class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        makeSubsets(nums, {}, 0, res);
        return res;
    }

    void makeSubsets(vector<int>& nums, vector<int> subset, int i, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }
        auto included = subset;
        included.push_back(nums[i]);
        makeSubsets(nums, subset, i+1, res);
        makeSubsets(nums, included, i+1, res);
    }
};
