class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        if(n==1 and grid[0][0]==0) return 1;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>>q; //{dist,{row,col}};
        q.push({1,{0,0}});
        dist[0][0] = 0;
        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int drow = row + i;
                    int dcol = col + j;

                    if(drow>=0 && drow<n && dcol>=0 && dcol<n && grid[drow][dcol]==0 && dist[drow][dcol]>dis + 1){
                        dist[drow][dcol] = dis+1;
                        if(drow==n-1 && dcol==n-1) return dis+1;
                        q.push({dis+1, {drow,dcol} }); 
                    }
                    
                }
            }
        }
        return -1;

    }
};