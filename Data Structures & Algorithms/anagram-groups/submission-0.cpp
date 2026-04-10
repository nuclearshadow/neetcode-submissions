class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> groups;
        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            groups[key].push_back(str);
        }
        vector<vector<string>> result;
        for (const auto& [key, group] : groups) {
            result.push_back(group);
        }
        return result;
    }
};
