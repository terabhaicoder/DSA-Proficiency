class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int sm=0;
        int m=rolls.size();

        for(auto x:rolls){
            sm=sm+x;
        }

        int ts=(m+n)*mean;

        int sr=ts-sm;

        vector<int>ans(n,0);
        int i=0;

        if(sr<n) return {};

        while(sr--){
            ans[(i++)%n]++;
            if(ans[(i-1)%n]>6) return {};
        }

        return ans;
    }
};