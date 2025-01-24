class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int first = intervals[i][0];
            int second = intervals[i][1];
            if(ans.size()==0) ans.push_back({first,second});
            else if(ans.back()[1] >= first ) {
                ans.back()[1] = max(second,ans.back()[1]);
            }
            else {
                 ans.push_back({first,second});
            }
        }
        return ans;
    }
};