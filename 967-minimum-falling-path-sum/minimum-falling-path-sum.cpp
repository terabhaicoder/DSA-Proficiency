class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(j<0 || j>=matrix.size()) return 1e9;
        if(i==0) return dp[0][j] = matrix[0][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int up = matrix[i][j] + solve(i-1,j,matrix,dp);
        int leftdiag = matrix[i][j] + solve(i-1,j-1,matrix,dp);
        int rightdiag = matrix[i][j] + solve(i-1,j+1,matrix,dp);
        return dp[i][j] = min(up,min(leftdiag,rightdiag));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
        for(int j=0;j<m;j++){
            int a = solve(m-1,j,matrix,dp);
            if(a<ans) ans = a;
        }
        return ans;

        
    }
};