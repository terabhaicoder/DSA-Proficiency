class Solution {
public:
    int t[301];
    bool f(int idx,string s,unordered_set<string>st){
        if(idx==s.size()){
            return t[idx] = true;
        }
        if(t[idx]!=-1) return t[idx];
        if(st.find(s)!=st.end()) return true;

        for(int i=0;i<=s.size();i++){
            string temp = s.substr(idx,i);
            if(st.find(temp)!=st.end() && f(idx + i,s,st)) return t[idx] = true;
        }
        return t[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        memset(t,-1, sizeof(t));
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        return f(0,s,st);
    }
};