class Solution {
public:
    int ans(int n,vector<int>&dp){
        if(n==0) return dp[0] = 1;
        if(n==1) return dp[1] = 1;
        if(dp[n]!=-1) return dp[n];
        int left = ans(n-1,dp);
        int right = ans(n-2,dp);
        return dp[n] = left+right;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return ans(n,dp);
    }
};