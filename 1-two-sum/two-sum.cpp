class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int diff = target-nums[i];
            if(mpp.find(diff)==mpp.end()){
                mpp[nums[i]]=i;
            }
            else {
                ans.push_back(mpp[diff]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
        
    }
};