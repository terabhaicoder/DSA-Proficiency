class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot = -1;

        for(int i=0;i<nums.size();i++){
            int left = 0;
            int right = 0;
            for(int j=0;j<=i-1;j++){
                left+=nums[j];
            }
            for(int k=i+1;k<nums.size();k++){
                right+=nums[k];
                //if(right>left) break;
            }
            if(left==right){
                pivot = i;
                break;
            }
        }
        return pivot;
    }
};