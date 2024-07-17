class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>>merge;
        merge.push_back(points[0]);
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=merge.back()[1]){
                int first = max(points[i][0],merge.back()[0]);
                int second = min(points[i][1],merge.back()[1]);
                merge.back()[0] = first;
                merge.back()[1] = second;
            }
            else merge.push_back(points[i]);
        }
        return merge.size();

    }
};