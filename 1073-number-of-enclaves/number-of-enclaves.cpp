class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int row,int col,int drow[],int dcol[],int n,int m){
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(grid,vis,nrow,ncol,drow,dcol,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        int cnt = 0;

        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !vis[0][i]) dfs(grid,vis,0,i,drow,dcol,n,m);
            if(grid[n-1][i]==1 && !vis[n-1][i]) dfs(grid,vis,n-1,i,drow,dcol,n,m);
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]) dfs(grid,vis,i,0,drow,dcol,n,m);
            if(grid[i][m-1]==1 && !vis[i][m-1]) dfs(grid,vis,i,m-1,drow,dcol,n,m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};