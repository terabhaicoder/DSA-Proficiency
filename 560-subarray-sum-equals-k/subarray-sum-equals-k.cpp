class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<long long ,int>mpp;
        long long sum = 0;
        mpp[0] = 1;
        int cnt = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            long long rem = sum - k;
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};