class Solution {
public:
    int f(int ind,int buy,vector<int>& prices,int n,vector<vector<int>>&dp){
        if(ind>=n) return 0;
        int profit = 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            profit = max(-prices[ind] + f(ind+1,0,prices,n,dp), f(ind+1,1,prices,n,dp));
        }
        else {
            profit = max(prices[ind] + f(ind+2,1,prices,n,dp), f(ind+1,0,prices,n,dp));
        }
        return dp[ind][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,n,dp);
    }
};