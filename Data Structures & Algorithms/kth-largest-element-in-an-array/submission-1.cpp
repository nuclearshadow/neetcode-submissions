class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;

        for (auto num : nums) {
            if (heap.size() < k) {
                heap.push(num);
            } else if (num > heap.top()) {
                heap.pop();
                heap.push(num);
            }
        }
        return heap.top();
    }
};
