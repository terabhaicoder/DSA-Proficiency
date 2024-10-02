class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a = arr;
        sort(a.begin(),a.end());
        int n = a.size();
        unordered_map<int,int>mpp;
        int num = 1;
        for(int i=0;i<n;i++){
            mpp[a[i]] = num;
            if(i<n-1 && a[i]!=a[i+1])num++; 
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(mpp[arr[i]]);
        }
        return ans;
    }
};