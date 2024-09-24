class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_set<int>st;
        for(auto val : arr1){
            while(!st.count(val) && val>0){
                st.insert(val);
                val = val/10;
            }
        }
        for(auto it : arr2){
            while(!st.count(it) && it>0){
                it = it/10;
            }
            if(it>0)ans = max(ans,int(log10(it)+1));

        }
        return ans;

    }
};