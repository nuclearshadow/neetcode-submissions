class TimeMap {
public:
    TimeMap() {
        store = map<string, vector<pair<string, int>>>();
    }
    
    void set(string key, string value, int timestamp) {
        if (!store.contains(key)) {
            store[key] = vector<pair<string, int>>();
        }
        store[key].push_back({ value, timestamp });
    }
    
    string get(string key, int timestamp) {
        if (!store.contains(key) || timestamp < store[key][0].second) {
            return "";
        }
        auto& values = store[key];
        for (auto it = values.rbegin(); it != values.rend(); it++) {
            if (it->second <= timestamp) {
                return it->first;
            }
        }
        return "";
    }

private:
    map<string, vector<pair<string, int>>> store;
};
