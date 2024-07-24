class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int target = n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i>=target) target = i;
        }
        if(target==0) return true;
        return false;
    }
};