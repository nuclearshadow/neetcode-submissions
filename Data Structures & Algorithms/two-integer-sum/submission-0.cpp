class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numIdx;
        for (int i = 0; i < nums.size(); i++) {
            if (numIdx.contains(target - nums[i])) {
                return {numIdx[target - nums[i]], i};
            }
            numIdx[nums[i]] = i;
        }
        return {};
    }
};
