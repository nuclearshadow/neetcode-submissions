class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for (int i = 0; i <= nums.size() - k; i++) {
            int wmax = nums[i];
            for (int j = i+1; j < i+k; j++) {
                wmax = max(wmax, nums[j]);
            }
            res.push_back(wmax);
        }
        return res;
    }
};
