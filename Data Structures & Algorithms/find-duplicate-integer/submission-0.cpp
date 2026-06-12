class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (auto& n : nums) {
            if (nums[abs(n) - 1] < 0) {
                return abs(n);
            }
            nums[abs(n) - 1] *= -1;
        }
        return 0;
    }
};
