class Solution {
public:
    void f(int idx,string digits,unordered_map<char,string>&mpp,vector<string>&ans,string &s){
        if(idx>=digits.size()) ans.push_back(s);
        char st = digits[idx];
        string str = mpp[st];
        for(int i=0;i<str.size();i++){
            s.push_back(str[i]);
            f(idx+1,digits,mpp,ans,s);
            s.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
         if(digits.size()==0) return {};
        unordered_map<char,string>mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        vector<string>ans;
       
        string s="";
        f(0,digits,mpp,ans,s);
        return ans;
    }
};