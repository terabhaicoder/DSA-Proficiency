class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        int size = m*n;
        if(original.size()!=size) return ans;
        vector<int>temp;
        for(int i=0;i<original.size();i++){
            temp.push_back(original[i]); 
            if(temp.size()==n){
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};