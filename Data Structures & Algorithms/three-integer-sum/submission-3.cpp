class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> seen;
        
        sort(nums.begin(), nums.end());


        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] == -nums[i]) {
                    vector<int> triple = { nums[i], nums[j], nums[k] };
                    sort(triple.begin(), triple.end());
                    if (!seen.contains(triple)) {
                        res.push_back(triple);
                        seen.insert(triple);
                    }
                    j++; k--;
                }
                if (nums[j] + nums[k] < -nums[i]) j++;
                if (nums[j] + nums[k] > -nums[i]) k--;
            }
        }
        
        return res;
    }
};
