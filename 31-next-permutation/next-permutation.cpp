class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = -1;
        int n = nums.size();
        for(int j=n-2;j>=0;j--)
        if(nums[j]<nums[j+1]){
            i = j;
            break;
        }
        if(i==-1) {
            reverse(nums.begin(),nums.end());
        }
        else {
            for(int j=n-1;j>=i;j--){
                if(nums[j]>nums[i]){
                    swap(nums[i],nums[j]);
                    break;
                }
            }
            reverse(nums.begin()+i+1,nums.end());
        }
        }
};