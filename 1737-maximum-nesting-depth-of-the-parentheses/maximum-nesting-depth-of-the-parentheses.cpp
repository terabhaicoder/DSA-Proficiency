class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') count++;
            else if(s[i] == ')'){
                maxi = max(maxi,count);
                count--;
            }
            else continue;
        }
        return maxi;
    }
};