class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (i < nums1.size() && (j >= nums2.size() || nums1[i] < nums2[j])) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
            cout << merged[merged.size() - 1] << " ";
        }
        cout << "\n" << merged.size();
        return merged.size() % 2 == 0 
            ? (merged[merged.size()/2 - 1] + merged[merged.size()/2]) / 2.0
            : merged[merged.size()/2];
    }
};
