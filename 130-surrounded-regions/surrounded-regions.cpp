class Solution {
public:
    void dfs(vector<vector<char>>&board,vector<vector<int>>&vis,int row,int col,int drow[],int dcol[],int n,int m){
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(board,vis,nrow,ncol,drow,dcol,n,m);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]) dfs(board,vis,0,j,drow,dcol,n,m);
            if(board[n-1][j]=='O' && !vis[n-1][j]) dfs(board,vis,n-1,j,drow,dcol,n,m);
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]) dfs(board,vis,i,0,drow,dcol,n,m);
            if(board[i][m-1]=='O' && !vis[i][m-1]) dfs(board,vis,i,m-1,drow,dcol,n,m);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
};