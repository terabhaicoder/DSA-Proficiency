class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>v(n,vector<int>(m,0));
        int i=0,j=0;
        while(i<n && j<m){
            v[i][j] = min(rowSum[i],colSum[j]);
            rowSum[i]-=v[i][j];
            colSum[j]-=v[i][j];
           if(rowSum[i]==0) i++;
            if(colSum[j]==0) j++;

        }
       return v;
    }
};