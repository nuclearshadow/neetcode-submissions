class Solution {
public:
    int climbStairs(int n) {
        int n1 = 1, n2 = 2;
        if (n == 1 || n == 2) return n;
        for (int i = 3; i <= n; i++) {
            int temp = n2;
            n2 = n1 + n2;
            n1 = temp;
        }
        return n2;
    }
};
