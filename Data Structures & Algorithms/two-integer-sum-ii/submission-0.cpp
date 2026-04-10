class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int idx = lower_bound(numbers.begin(), numbers.end(), target - numbers[i]) - numbers.begin();
            if (numbers[idx] == target - numbers[i]) {
                if (idx < i) return {idx + 1, i + 1};
                return {i + 1, idx + 1};
            }
        }
        return {};
    }
};
