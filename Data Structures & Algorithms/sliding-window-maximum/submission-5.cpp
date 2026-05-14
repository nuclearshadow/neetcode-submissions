using pii = std::pair<int, int>;

struct Compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pii, std::vector<pii>, Compare> q;
        for (int i = 0; i < k; i++) {
            q.push({i, nums[i]});
        }
        res.push_back(q.top().second);
        for (int i = 1; i <= nums.size() - k; i++) {
            while (!q.empty() && (q.top().first < i || q.top().first >= i+k)) {
                q.pop();
            }
            q.push({i+k-1, nums[i+k-1]});
            res.push_back(q.top().second);
        }
        return res;
    }
};
