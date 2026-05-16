class Solution {
    map<int, int> mem;

public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        if (mem.contains(n)) {
            return mem[n];
        }
        int res = climbStairs(n-1) + climbStairs(n-2);
        return mem[n] = res;
    }
};
