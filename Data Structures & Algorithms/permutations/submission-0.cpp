class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        rec(nums, vector<bool>(nums.size(), false), {}, res);
        return res;
    }

    void rec(
        vector<int>& nums, 
        vector<bool> picked, 
        vector<int> perm,
        vector<vector<int>>& res 
    ) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (picked[i]) continue;
            auto included = perm;
            included.push_back(nums[i]);
            auto newpicked = picked;
            newpicked[i] = true;
            rec(nums, newpicked, included, res);
        }
    }
};
