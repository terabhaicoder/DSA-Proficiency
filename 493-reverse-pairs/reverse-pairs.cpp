class Solution {
public:
    int merge(vector<int> &nums, int low, int mid, int high){
        int j = mid+1;
        int cnt = 0;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i]>nums[j]*2LL){
                j++;
            }
            cnt = cnt + (j - (mid +1));
        }
        
        vector <int> temp;
        int left=low, right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=high){
            temp.push_back(nums[right++]);
        }
        for(int i=low; i<=high; i++){
            nums[i] = temp[i-low];
        }
        return cnt;
    }
    
    int mergesort(vector<int> &nums, int low, int high){
        if(low==high) return 0;
        int mid = (low + high)/2;
        int inv = mergesort(nums, low, mid);
        inv += mergesort(nums, mid+1, high);
        inv += merge(nums, low, mid, high);
        return inv;
    }
   int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size()-1);  
    }
};