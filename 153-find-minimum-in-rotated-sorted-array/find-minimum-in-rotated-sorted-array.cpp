class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=nums[low]){
                ans = min(ans,nums[low]);
                low = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};