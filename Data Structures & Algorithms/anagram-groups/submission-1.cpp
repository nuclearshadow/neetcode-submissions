class Solution {
    using Key = map<char, int>;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<Key, vector<string>> groups;
        for (const string& str : strs) {
            auto key = createKey(str);
            groups[key].push_back(str);
        }
        vector<vector<string>> result;
        for (const auto& [key, group] : groups) {
            result.push_back(group);
        }
        return result;
    }

    Key createKey(const string& str) {
        map<char, int> res;
        for (char c : str) {
            res[c] += 1;
        }
        return res;
    }
};
