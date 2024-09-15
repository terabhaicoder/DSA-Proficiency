class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int v = 0;
            int c = 0;
            for(int j=i;j<n;j++){
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u') v++;
                else c++;
                if(c==v && (c*v)%k==0) cnt++;
            }
        }
        return cnt;
    }
};