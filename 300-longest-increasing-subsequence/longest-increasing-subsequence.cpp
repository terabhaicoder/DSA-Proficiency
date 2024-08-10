class Solution {
public:
    int f(int ind,int n,vector<int>& nums,int prev_ind,vector<vector<int>>&dp){
        if(ind==n){
            return 0;
        }
        int take = 0;
        if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
        if(prev_ind==-1 || nums[prev_ind]<nums[ind]) take = 1 + f(ind+1,n,nums,ind,dp);

        int nottake = f(ind+1,n,nums,prev_ind,dp);

        return dp[ind][prev_ind+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,n,nums,-1,dp);
    }
};