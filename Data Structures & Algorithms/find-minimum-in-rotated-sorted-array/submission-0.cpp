class Solution {
public:
    int findMin(vector<int> &nums) {
        int minnum = INT_MAX;
        for (auto n : nums) {
            minnum = min(minnum, n);
        }
        return minnum;
    }
};
