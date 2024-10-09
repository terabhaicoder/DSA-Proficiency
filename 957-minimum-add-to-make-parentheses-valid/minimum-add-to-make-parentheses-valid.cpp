class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int cnt = 0;
        for(auto it : s){
            if(it=='(') st.push('(');
            if(it==')'){
                if(!st.empty()) st.pop();
                else cnt++;
            }
        }
        return st.size() + cnt;
    }
};