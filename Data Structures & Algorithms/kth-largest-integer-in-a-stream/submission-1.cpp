class KthLargest {
    int k;
    vector<int> sorted;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        sort(nums.begin(), nums.end());
        this->sorted = nums;
    }
    
    int add(int val) {
        int idx = sorted.size();
        sorted.push_back(0);
        while (idx > 0 && val < sorted[idx - 1]) {
            sorted[idx] = sorted[idx - 1];
            idx--;
        }
        sorted[idx] = val;
        return sorted[sorted.size() - k];
    }
};
