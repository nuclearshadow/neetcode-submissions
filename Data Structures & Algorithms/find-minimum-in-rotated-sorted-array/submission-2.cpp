class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int mine = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= nums[l]) {
                mine = min(mine, nums[l]);
                l = mid + 1;
            } else {
                mine = min(mine, nums[mid]);
                r = mid - 1;
            }
        }
        return mine;
    }
};
