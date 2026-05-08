class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int n = height.size();

        int prefix[height.size()];
        int suffix[height.size()];

        std::cout << "Prefix: 0";
        prefix[0] = 0;
        for (int i = 1; i < height.size(); i++) {
            prefix[i] = max(height[i-1], prefix[i-1]);
            std::cout << ", " << prefix[i];
        }
        std::cout << "\nSuffix: ";
        suffix[height.size()-1] = 0;
        for (int i = height.size() - 2; i >= 0; i--) {
            suffix[i] = max(height[i+1], suffix[i+1]);
            std::cout << suffix[i] << ", ";
        }
        std::cout << "0\n";

        for (int i = 1; i < n - 1; i++) {
            water += max(0, min(prefix[i], suffix[i]) - height[i]);
        }

        return water;
    }
};