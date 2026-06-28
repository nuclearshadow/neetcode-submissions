class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->heap = priority_queue<int, vector<int>, greater<int>>();
        for (auto num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (heap.size() < k) {
            heap.push(val);
        } else if (heap.top() < val) {
            heap.pop();
            heap.push(val);
        }
        return heap.top();
    }
};
