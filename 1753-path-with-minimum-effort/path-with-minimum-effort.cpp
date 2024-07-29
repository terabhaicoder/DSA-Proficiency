typedef pair<int,pair<int,int>> P;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<P,vector<P>,greater<P>>pq; //{effort,{row,col}}

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 && col==m-1) return diff;
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int neweff = max ( abs(heights[row][col] - heights[nrow][ncol] ), diff);
                    if(neweff < dist[nrow][ncol]){
                        dist[nrow][ncol] =neweff;
                        pq.push({neweff,{nrow,ncol}}); 
                    }
                } 
            }
        }
        return -1;

    }

};