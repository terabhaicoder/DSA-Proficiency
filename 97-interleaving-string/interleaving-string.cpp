class Solution {
public:
    int t[101][101][201];
    bool f(int i,int j,int k,string& s1, string& s2, string &s3){
        if(i==s1.length() && j== s2.length() && k==s3.length()) return true;
        if(k>=s3.length()) return false;
        bool result = false;
        if(t[i][j][k] != -1 ) return t[i][j][k];
        if(s1[i]==s3[k]) result = f(i+1,j,k+1,s1,s2,s3);
        if(result) return true;
        if(s2[j]==s3[k]) result = f(i,j+1,k+1,s1,s2,s3);

        return t[i][j][k] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        int n = s3.size();
        memset(t,-1,sizeof(t));
        return f(0,0,0,s1,s2,s3);
    }
};