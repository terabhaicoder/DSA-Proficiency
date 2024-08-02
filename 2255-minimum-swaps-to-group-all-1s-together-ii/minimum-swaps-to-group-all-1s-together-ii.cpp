class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalones=0;
        int n = nums.size();
        for(int i=0;i<n;i++) totalones+=nums[i];

        int i=0;
        int j=0;
        int currones = 0;
        int maxcount = 0;
        while(j<2*n){
            if(nums[j%n]==1) currones++;
            if(j-i+1 > totalones){
                currones-=nums[i%n];
                i++;
            }
            maxcount = max(maxcount,currones);
            j++;
        }
        return totalones - maxcount;
    }
};