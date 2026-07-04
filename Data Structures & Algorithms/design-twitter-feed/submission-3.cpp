class Twitter {
    int time = 0;
    map<int, set<int>> follows;
    map<int, vector<pair<int, int>>> tweets;
public:
    Twitter() : follows(), tweets() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> heap;
        vector<int> res;
        if (tweets[userId].size() > 0) {
            auto [time, tweet] = tweets[userId].back();
            heap.push({time, tweet, userId, tweets[userId].size()-1});
        }
        for (auto followee : follows[userId]) {
            if (followee == userId) continue;
            if (tweets[followee].size() <= 0) continue;
            auto [time, tweet] = tweets[followee].back();
            heap.push({time, tweet, followee, tweets[followee].size()-1});
        }
        for (int i = 0; i < 10 && !heap.empty(); i++) {
            auto [_, tweet, user, index] = heap.top();
            res.push_back(tweet);
            heap.pop();
            if (index > 0) {
                auto [time, tweet] = tweets[user][index-1];
                heap.push({time, tweet, user, index-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
