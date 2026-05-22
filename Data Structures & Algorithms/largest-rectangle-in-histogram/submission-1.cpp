class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        for (int i = 0; i <= heights.size(); i++) {
            int cur = i == heights.size() ? 0 : heights[i];
            while (!s.empty() && cur <= heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int left = s.empty() ? -1 : s.top();
                maxArea = max(maxArea, height * (i - left - 1));
            }
            s.push(i);
        }
        return maxArea;
    }
};
