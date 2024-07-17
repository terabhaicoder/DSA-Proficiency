class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int start = nums[i];

            while(i+1<n && nums[i+1]==1+nums[i]){
                i++;
            }
            if(start!=nums[i]){   
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
            else ans.push_back(to_string(start));
        }
        return ans;
    }
};