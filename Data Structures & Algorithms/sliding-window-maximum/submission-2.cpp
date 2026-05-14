class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        vector<int> q;
        for (int i = 0; i < k; i++) {
            q.push_back(nums[i]);
        }
        make_heap(q.begin(), q.end());
        res.push_back(q.front());
        for (int i = 1; i <= nums.size() - k; i++) {
            auto it = find(q.begin(), q.end(), nums[i-1]);
            q.erase(it);
            make_heap(q.begin(), q.end());

            q.push_back(nums[i+k-1]);
            push_heap(q.begin(), q.end());
            res.push_back(q.front());
        }
        return res;
    }
};
