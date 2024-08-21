class Solution {
private:
    vector<vector<int>> dp;
    int helper(int l,int r,string s){
        if(l>r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int res = 1+helper(l+1,r,s);
        for(int i=l+1;i<=r;i++){
            if(s[l]==s[i]){
                res = min(res,helper(l,i-1,s) + helper(i+1,r,s));
            }
        } 
        return dp[l][r] = res;
    }
public:
    int strangePrinter(string s) {
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        return helper(0,n-1,s);
    }
};