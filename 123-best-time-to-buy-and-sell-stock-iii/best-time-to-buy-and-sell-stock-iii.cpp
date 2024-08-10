class Solution {
public:
    int f(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>>&dp){
        if(ind==n) return 0;
        if(cap==0) return 0;
        int profit = 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            profit = max(-prices[ind] + f(ind+1,0,cap,prices,n,dp), f(ind+1,1,cap,prices,n,dp));
        }
        else {
            profit = max(prices[ind] + f(ind+1,1,cap-1,prices,n,dp), f(ind+1,0,cap,prices,n,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,n,dp);
    }
};