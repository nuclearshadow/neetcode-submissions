class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int u = 0;
        for (auto p : piles) {
            u = max(u, p);
        }
        int mink = INT_MAX;
        while (l <= u) {
            int k = (l + u) / 2;
            int hours = 0;
            for (auto p : piles) {
                hours += (int) ceil((double)p / k);
            }
            if (hours > h) {
                l = k + 1;
            } else {
                u = k - 1;
                mink = min(mink, k);
            }
        }
        return mink;
    }
};
