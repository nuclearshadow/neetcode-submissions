class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        vector<int> buckets[nums.size() + 1];

        for (auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }

        vector<int> result;

        for (int i = nums.size(); i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;

    }
};
