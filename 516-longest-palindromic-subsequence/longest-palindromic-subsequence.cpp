class Solution {
public:
    int find(int i,int j,string &s,string &a,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==a[j]){
            return dp[i][j]= 1 + find(i-1,j-1,s,a,dp);
        }
        return dp[i][j] = max(find(i-1,j,s,a,dp),find(i,j-1,s,a,dp));
    }
    int longestPalindromeSubseq(string s) {
        string a = s;
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        reverse(s.begin(),s.end());
        return find(n-1,n-1,s,a,dp);
    }
};