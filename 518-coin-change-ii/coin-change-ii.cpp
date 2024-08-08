class Solution {
public:
    int f(int ind,int target,vector<int>& coins,vector<vector<int>>&dp){
        if(ind==0){
            if(target%coins[0]==0) return 1;
            else return dp[ind][target] = 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int nottake = 0 + f(ind-1,target,coins,dp);
        int take = 0;
        if(coins[ind]<=target) take = f(ind,target-coins[ind],coins,dp);

        return dp[ind][target] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {
         int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};