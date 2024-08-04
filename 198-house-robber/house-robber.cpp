class Solution {
public:
    int solve(vector<int>&nums,int i, int maxi,vector<int>&dp){
        if(i==0) return dp[0] = nums[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int left = 0 + solve(nums,i-1,maxi,dp);
        int right = nums[i] + solve(nums,i-2,maxi,dp);

        maxi = max(left,right);
        return dp[i] = maxi;
    }
    int rob(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,n-1,maxi,dp);
    }
};