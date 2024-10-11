class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int target = times[targetFriend][0];

        sort(times.begin(),times.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> bag;

        priority_queue<int,vector<int>,greater<int>> free;

        int seat=0;

        int ind=0;

        for(int i=1;i<1e5+1;i++){
            if(!bag.empty() && bag.top().first<=i){
                free.push(bag.top().second);
                bag.pop();
            }

            if(times[ind][0]==i){
                if(!free.empty()){
                    bag.push({times[ind][1],free.top()});
                    if(times[ind][0]==target)return free.top();
                    free.pop();
                }

                else{
                    bag.push({times[ind][1],seat});
                    if(times[ind][0]==target)return seat;
                    seat++;
                }

                ind++;
            }
            
        }
        return -1;
    }
};