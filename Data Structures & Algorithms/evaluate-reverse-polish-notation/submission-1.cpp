class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto token : tokens) {
            if (isOperator(token)) {
                int num2 = s.top(); s.pop();
                int num1 = s.top(); s.pop();
                s.push(applyOperator(token, num1, num2));
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }

    bool isOperator(string token) {
        return token == "+" ||
               token == "-" ||
               token == "*" ||
               token == "/";
    }

    int applyOperator(string op, int num1, int num2) {
        if (op == "+") {
            return num1 + num2;
        } else if (op == "-") {
            return num1 - num2;
        } else if (op == "*") {
            return num1 * num2;
        } else if (op == "/") {
            return num1 / num2;
        }
    }
};
