class Solution {
public:
     int find(int i,int j,string &text1, string &text2,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j] = 1 + find(i-1,j-1,text1,text2,dp);
        return dp[i][j] = max(find(i-1,j,text1,text2,dp),find(i,j-1,text1,text2,dp));
    }

    int minDistance(string word1, string word2) {
         int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int a =  find(n-1,m-1,word1,word2,dp);

        return (m+n - 2*a);
    }
};