class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() : left(), right() {
        
    }
    
    void addNum(int num) {
        if (right.size() == 0 || num > right.top()) {
            right.push(num);
        } else {
            left.push(num);
        }
        int diff = right.size() - left.size();
        if (diff > 1) {
            left.push(right.top());
            right.pop();
        } else if (diff < -1) {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }
        if (right.size() > left.size()) {
            return right.top();
        }
        return (left.top() + right.top()) / 2.0;
    }
};
