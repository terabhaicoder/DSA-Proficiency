class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(st.find(nums[i])!=st.end()){
                return true;
            }
            else st.insert(nums[i]);
        }
        return false;
    }
};