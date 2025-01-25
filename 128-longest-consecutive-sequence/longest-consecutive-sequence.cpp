class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        // for(int i=0;i<n;i++){
        //     int x = nums[i];
        //     while(st.find(x-1)!=st.end()){
        //         x--;
        //     }
        //     int count = 1;
        //     while(st.find(x+1)!=st.end()){
        //         x++;
        //         count++;
        //     }
        //     ans = max(ans,count);

        // }
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int count = 1;
                int x = it;
                while(st.find(x+1)!=st.end()){
                    count++;
                    x++;
                }
                ans = max(ans,count);
            }

        }
        return ans;
    }
};