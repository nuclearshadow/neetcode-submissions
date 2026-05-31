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
        int l = 0, r = values.size() - 1;
        int maxt = 0;
        string maxvalue = "";
        while (l <= r) {
            int mid = (l + r) / 2;
            if (values[mid].second <= timestamp && maxt < values[mid].second) {
                maxt = values[mid].second;
                maxvalue = values[mid].first;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return maxvalue;
    }

private:
    map<string, vector<pair<string, int>>> store;
};
