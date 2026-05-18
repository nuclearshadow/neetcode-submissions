class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> s;
        vector<pair<int, int>> cars(position.size());
        for (int i = 0; i < cars.size(); i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end(), greater<>());

        for (auto [position, speed] : cars) {
            float time = (float)(target - position) / speed;
            if (s.empty() || s.top() < time) {
                s.push(time);
            }
        }
        return s.size();
    }
};
