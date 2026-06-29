class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto heap = priority_queue<pair<float, int>>();
        for (int i = 0; i < points.size(); i++) {
            auto& point = points[i];
            auto dist = sqrtf(point[0] * point[0] + point[1] * point[1]);
            if (heap.size() < k) {
                heap.push({dist, i});
            } else if (dist < heap.top().first) {
                heap.pop();
                heap.push({dist, i});
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back(points[heap.top().second]);
            heap.pop();
        }
        return res;
    }
};
