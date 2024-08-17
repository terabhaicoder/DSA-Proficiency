class Solution {
public:
    void f(int idx,vector<vector<int>>&ans,vector<int>&val,vector<int>v,int n,int k){
        if(k==0) ans.push_back(val);
        for(int i=idx;i<n;i++){
            val.push_back(v[i]);
            f(i+1,ans,val,v,n,k-1);
            val.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v(n);
        for(int i=0;i<n;i++) v[i] = i+1;
        vector<vector<int>>ans;
        vector<int>val;
        f(0,ans,val,v,n,k);
        return ans;
    }
};