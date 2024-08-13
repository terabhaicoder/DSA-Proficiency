class Solution {
public:
    void find(int ind,vector<int>nums,int target,vector<vector<int>>&ans,vector<int>&ds){
        int n = nums.size();
            if(target==0){
                ans.push_back(ds);
                return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            ds.push_back(nums[i]);
            find(i+1,nums,target-nums[i],ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int>ds;
        vector<vector<int>>ans;

        sort(candidates.begin(),candidates.end());
        find(0,candidates,target,ans,ds);
        return ans;
    }
};