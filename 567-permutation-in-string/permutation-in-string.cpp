class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n>m) return false;
        unordered_set<string>st;
        for(int i=0;i<=m-n;i++){
            string s = s2.substr(i,n);
            sort(s.begin(),s.end());
            st.insert(s);
        }
        sort(s1.begin(),s1.end());
        if(st.find(s1)==st.end()) return false;
        return true;
    }
};