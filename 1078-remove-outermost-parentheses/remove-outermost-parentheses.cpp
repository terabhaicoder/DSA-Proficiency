class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        //int close = 0;
        int n = s.size();
        string st = "";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
                if(open>1) st = st + '(';
            }
            else {
                if(open>1) st = st + ')';
                open--;
            }
        }

        return st;
    }
};