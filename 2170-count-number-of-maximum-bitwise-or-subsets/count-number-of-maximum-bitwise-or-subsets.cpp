class Solution {
private:
    int func(vector<int>& nums, int i){
        if(i<0) return 0;
        int take=nums[i]|func(nums,i-1);
        int nottake=func(nums,i-1);
        return max(take,nottake);
    }
    int func1(vector<int>& nums, int i,int target, int cur){
        if(i<0){
            if(cur==target) return 1;
            return 0;
        }
        int take=func1(nums,i-1,target,nums[i]|cur);
        int nottake=func1(nums,i-1,target,cur);
        return take+nottake;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxi = func(nums,n-1);
        cout<<maxi;
        return func1(nums,n-1,maxi,0);
    }
};