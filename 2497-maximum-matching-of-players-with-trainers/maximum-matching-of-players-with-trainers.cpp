class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int l=0,r=0;
        int ans = 0;
        while(r<trainers.size()){
            if(l<players.size() && players[l]<=trainers[r]){
                l++;
                ans++;
            }
            r++;
        }
        return ans;
    }
};