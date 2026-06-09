#include <cassert>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& smaller = nums1.size() <= nums2.size() ? nums1 : nums2;
        vector<int>& other   = nums1.size() <= nums2.size() ? nums2 : nums1;

        int l = 0, r = smaller.size();
        int lefta, righta, leftb, rightb;
        while (l <= r) {
            int i = (l + r) / 2;
            int j = (smaller.size() + other.size() + 1) / 2 - i;
            lefta = i == 0 ? INT_MIN : smaller[i-1];
            righta = i == smaller.size() ? INT_MAX : smaller[i];
            leftb = j == 0 ? INT_MIN : other[j-1];
            rightb = j == other.size() ? INT_MAX : other[j];
            if (lefta <= rightb && leftb <= righta) {
                break;
            } else if (lefta > rightb) {
                r = i - 1;
            } else if (leftb > righta) {
                l = i + 1;
            } else {
                assert(0 && "unreachable");
            }
        }
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            return (max(lefta, leftb) + min(righta, rightb)) / 2.0;
        }
        return max(lefta, leftb);
    }
};
