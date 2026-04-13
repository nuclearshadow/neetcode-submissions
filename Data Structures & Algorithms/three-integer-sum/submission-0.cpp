class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> seen;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                for (int k = j+1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triple = {nums[i], nums[j], nums[k]};
                        auto triplekey = triple;
                        sort(triplekey.begin(), triplekey.end());
                        if (!seen.contains(triplekey)) {
                            res.push_back(triple);
                            seen.insert(triplekey);
                        }
                    }
                }
            }
        }
        return res;
    }
};
