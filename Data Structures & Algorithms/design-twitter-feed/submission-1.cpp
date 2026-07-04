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
        priority_queue<pair<int, int>> heap;
        vector<int> res;
        for (auto tweet : tweets[userId]) {
            heap.push(tweet);
        }
        for (auto followee : follows[userId]) {
            if (followee == userId) continue;
            for (auto tweet : tweets[followee]) {
                heap.push(tweet);
            }
        }
        for (int i = 0; i < 10 && !heap.empty(); i++) {
            res.push_back(heap.top().second);
            heap.pop();
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
