class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        for(const auto & interval : intervals){
            if(!pq.empty() && pq.top() < interval[0]){
                pq.pop();
            }
            pq.push(interval[1]);
        }
        return pq.size();
    }
};