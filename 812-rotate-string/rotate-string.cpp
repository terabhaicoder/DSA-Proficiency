class Solution {
public:
    bool rotateString(string s, string goal) {
        char start = s[0];
        if(s.size()!=goal.size()) return false;
        if(s==goal) return true;
        int n = goal.size();
        for(int i=0;i<n;i++){
            if(goal[i]==start){
                string x = goal.substr(i,n-i) + goal.substr(0,i);

                if(x==s) return true;
            }
        }
        return false;
    }
};