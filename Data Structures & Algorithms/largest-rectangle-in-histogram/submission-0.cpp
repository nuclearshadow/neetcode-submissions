class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            int l = i, r = i;
            while (l > 0 && heights[l-1] >= heights[i]) {
                l--;
            }
            while (r < heights.size() - 1 && heights[r+1] >= heights[i]) {
                r++;
            }
            maxArea = max(maxArea, heights[i] * (r - l + 1));
        }

        return maxArea;
    }
};
