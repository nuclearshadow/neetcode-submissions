struct QueueTask {
    int freq;
    int nextAvailTime;
    char task;
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> heap;
        int freq[26]= {0};
        for (auto task : tasks) {
            freq[task - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] <= 0) continue;
            heap.push({freq[i], i + 'A'});
        }
        queue<QueueTask> q;
        int time = 0;
        while (!heap.empty() || !q.empty()) {
            time++;
            if (!heap.empty()) {
                auto [freq, task] = heap.top(); heap.pop();
                if (freq > 1) {
                    q.push({ freq - 1, time + n, task });
                }
            }
            if (!q.empty()) {
                auto [freq, nextAvailTime, task] = q.front();
                if (nextAvailTime <= time) {
                    q.pop();
                    heap.push({freq, task});
                }
            }
        }
        return time;
    }
};
