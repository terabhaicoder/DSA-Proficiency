class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<vector<int>,vector<string>>mpp;
       if(strs.size()==0) return ans;
        for(int i=0;i<strs.size();i++){
            vector<int>count(26,0);
            for(auto ch : strs[i]){
                count[ch-'a']++;
            }
        mpp[count].push_back(strs[i]);
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};