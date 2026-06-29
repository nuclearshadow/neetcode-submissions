class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, end = nums.size() - 1;
        while (true) {
            int pivot = nums[end];
            int p = start;

            for (int i = start; i < end; i++) {
                if (nums[i] <= pivot) {
                    swap(nums[i], nums[p++]);
                }
            }
            swap(nums[end], nums[p]);
            if (p == nums.size() - k) {
                return pivot;
            }

            if (p < nums.size() - k) {
                start = p + 1;
            } else {
                end = p - 1;
            }
        }
    }
};