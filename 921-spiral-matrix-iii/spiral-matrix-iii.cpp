class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rs, int cs) {
        int n = rows * cols;
        int x = 1, y = 1;
        vector<vector<int>> result;
        while (result.size()<n) {
            for (int i = 0; i < x; i++) {
                if (rs >= 0 && rs < rows && cs >= 0 && cs < cols) {
                    result.push_back({rs, cs});
                }
                cs++;
            }
            x++;
            for (int i = 0; i < y; i++) {
                if (rs >= 0 && rs < rows && cs >= 0 && cs < cols) {
                    result.push_back({rs, cs});
                }
                rs++;
            }
            y++;
            for (int i = 0; i < x; i++) {
                if (rs >= 0 && rs < rows && cs >= 0 && cs < cols) {
                    result.push_back({rs, cs});
                }
                cs--;
            }
            x++;
            for (int i = 0; i < y; i++) {
                if (rs >= 0 && rs < rows && cs >= 0 && cs < cols) {
                    result.push_back({rs, cs});
                }
                rs--;
            }
            y++;
        }
        return result;
    }
};