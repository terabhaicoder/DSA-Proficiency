class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans=0;
        for(int j=1;j<n-1;j++){
            int countleftsmaller=0;
            int countleftlarger=0;
            int countrightsmaller=0;
            int countrightlarger=0;

            for(int i=0;i<j;i++){
                if(rating[i]<rating[j]) countleftsmaller++;
                else if(rating[i]>rating[j]) countleftlarger++;
            }
            for(int k=j+1;k<n;k++){
                if(rating[k]<rating[j]) countrightsmaller++;
                else if(rating[k]>rating[j]) countrightlarger++;
            }

            ans += (countleftsmaller*countrightlarger) + (countleftlarger*countrightsmaller);
        }
        return ans;
    }
};