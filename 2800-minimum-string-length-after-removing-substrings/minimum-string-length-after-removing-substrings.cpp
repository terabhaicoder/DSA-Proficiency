class Solution {
public:
    int minLength(string s) {
        while(true){
        int del = 0;
        int n = s.size();
        for(int i=0;i<n-1;i++){
            if((s[i]=='A' && s[i+1]=='B') || (s[i]=='C' && s[i+1]=='D')){
                s.erase(i,2);
                del+=1;
            }
        }
        if(del==0) break;
    }
        return s.size();
    }
};