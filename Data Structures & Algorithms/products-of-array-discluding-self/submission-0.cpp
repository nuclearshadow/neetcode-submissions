class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCount = 0;
        for (int num : nums) {
            if (num == 0) zeroCount++;
            else product *= num;
        }
        vector<int> output;
        for (int num : nums) {
            if (zeroCount == 0 && num != 0) {
                output.push_back(product / num);
            } else if (zeroCount == 1 && num == 0) {
                output.push_back(product);
            } else {
                output.push_back(0);
            }
        }
        return output;
    }
};
