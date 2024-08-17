class Solution {
public:
    void f(string &curr,int n,int open,int close,vector<string>&ans){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            f(curr,n,open+1,close,ans);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            f(curr,n,open,close+1,ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string>ans;
        string curr="";
        f(curr,n,open,close,ans);
        return ans;
    }
};