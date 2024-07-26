class Solution {
public:
    void bfs(vector<vector<int>>&ans,vector<vector<int>>&vis,int inicolor,int color,int row,int col){
        queue<pair<int,int>>q;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        int n = ans.size();
        int m = ans[0].size();
        
        q.push({row,col});
        ans[row][col] = color;
        vis[row][col] = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==inicolor && !vis[nrow][ncol]){
                    ans[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }

        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>>ans = image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        bfs(ans,vis,inicolor,color,sr,sc);
        return ans;
    }
};