class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        if (minstack.empty()) {
            minstack.push(val);
        } else {
            minstack.push(min(minstack.top(), val));
        }
        valstack.push(val);
    }
    
    void pop() {
        minstack.pop();
        valstack.pop();
    }
    
    int top() {
        return valstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
private:
    stack<int> valstack;
    stack<int> minstack;
};
