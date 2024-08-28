class Solution {
public:
    bool solve(vector<vector<int>> &g1,vector<vector<int>> &g2,int i,int j,int &m,int &n){
        if(i<0||j<0||i>=m||j>=n||g1[i][j]==3||g2[i][j]==3||(g1[i][j]==g2[i][j] && g1[i][j]==0)||g2[i][j]==0)return true;
        if(g1[i][j]==0 && g2[i][j]==1)return false;
        g1[i][j]= 3;
        g2[i][j]= 3;
        bool a1 = solve(g1,g2,i-1,j,m,n);
        bool a2 = solve(g1,g2,i,j-1,m,n);
        bool a3 = solve(g1,g2,i+1,j,m,n);
        bool a4 = solve(g1,g2,i,j+1,m,n);
        return (a1 && a2 && a3 && a4);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0,i,j,m = grid1.size(), n = grid1[0].size();
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(grid2[i][j] == 1 && grid2[i][j]==1){
                    ans += solve(grid1,grid2,i,j,m,n);
                }
            }
        }
        return ans;
    }
};