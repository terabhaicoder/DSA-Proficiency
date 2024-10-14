class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<nums.size();i++) pq.push(nums[i]);
        long long sum = 0;
        int n = nums.size();
        int i = 0;
        while(k>0){
            int x = pq.top();
            pq.pop();
            sum += x;
            x = (x+2)/3;
            pq.push(x);
            k--;
        }
        return sum;
    }
};