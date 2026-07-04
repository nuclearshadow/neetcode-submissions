class MedianFinder {
    vector<int> nums;
public:
    MedianFinder() : nums() {
        
    }
    
    void addNum(int num) {
        nums.push_back(0);
        int i = nums.size() - 1;
        while (i > 0 && nums[i-1] > num) {
            nums[i] = nums[i-1];
            i--;
        }
        nums[i] = num;
    }
    
    double findMedian() {
        int mid = nums.size()/2;
        if (nums.size() % 2 == 0) {
            return (nums[mid-1] + nums[mid]) / 2.0;
        }
        return nums[mid];
    }
};
