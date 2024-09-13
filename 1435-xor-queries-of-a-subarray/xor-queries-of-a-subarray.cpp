class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //int n = queries.size();
        vector<int>v;
        for(auto it : queries){
            int x = it[0];
            int y = it[1];
            int ans = 0;
            for(int i=x;i<=y;i++){
                ans = ans ^ arr[i];
            }
            v.push_back(ans);
        }
        return v;
    }
};