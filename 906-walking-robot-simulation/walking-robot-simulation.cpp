class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Direction vectors for North, East, South, West
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0; 
        int dir = 0; 
        set<pair<int, int>> st;
        for (const auto& obstacle : obstacles) {
            st.insert({obstacle[0], obstacle[1]});
        }

        int maxDist = 0;
        
        for (int cmd : commands) {
            if (cmd == -1) {
    
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir + 3) % 4; 
            } else {
                for (int step = 0; step < cmd; ++step) {
                    int nx = x + directions[dir].first;
                    int ny = y + directions[dir].second;
                    if (st.find({nx, ny}) == st.end()) {
                        x = nx;
                        y = ny;
                        maxDist = max(maxDist, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }
        return maxDist;
    }
};