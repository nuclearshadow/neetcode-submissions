class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        auto picked = vector<bool>(nums.size(), false);
        rec(nums, picked, perm, res);
        return res;
    }

    void rec(
        vector<int>& nums, 
        vector<bool>& picked, 
        vector<int>& perm,
        vector<vector<int>>& res 
    ) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (picked[i]) continue;
            perm.push_back(nums[i]);
            picked[i] = true;
            rec(nums, picked, perm, res);
            picked[i] = false;
            perm.pop_back();
        }
    }
};
