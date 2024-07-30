class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' && !st.empty() && st.top()=='b'){
                cnt++;
                st.pop();
            }
            else st.push(s[i]);
        }
        return cnt;
    }
};