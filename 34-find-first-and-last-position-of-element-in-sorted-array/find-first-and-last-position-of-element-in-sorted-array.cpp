class Solution {
public:
    void findfirst(vector<int>& nums, int n, int target, int &first){
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                first = mid;
                high = mid-1;
            } 
            else if(nums[mid]<target) low = mid+1; 
            else high = mid-1;
        }
    }
    void findlast(vector<int>& nums, int n, int target, int &last){
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                last = mid;
                low = mid+1;
            } 
            else if(nums[mid]<target) low = mid+1; 
            else high = mid-1;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1;
        int last = -1;
        findfirst(nums,n,target,first);
        if(first == -1) return {-1,-1};
        findlast(nums,n,target,last);
        return {first,last};
    }
};