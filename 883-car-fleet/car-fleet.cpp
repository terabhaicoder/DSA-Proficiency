class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
       vector<pair<int, double>> cars(n);
        for (int i=0;i<n;i++) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
    sort(cars.begin(), cars.end());
     stack<double> stack;
        for (int i=n-1;i>=0;i--){
            if (stack.empty() || cars[i].second > stack.top()) {
                stack.push(cars[i].second);
            }
        }
        return stack.size();
    }
};