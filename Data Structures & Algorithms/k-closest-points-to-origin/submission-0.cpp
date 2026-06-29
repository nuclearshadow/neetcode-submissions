class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<float, int>> pointsdistIdx;
        for (int i = 0; i < points.size(); i++) {
            auto& point = points[i];
            pointsdistIdx.push_back({sqrtf(point[0] * point[0] + point[1] * point[1]), i});
        }
        auto heap = priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>>(pointsdistIdx.begin(), pointsdistIdx.end());

        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back(points[heap.top().second]);
            heap.pop();
        }
        return res;
    }
};
