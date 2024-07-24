class Solution {
public:
    string mapped(string &s,vector<int>&mapping){
        string num = "";
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            int chint = s[i]-'0';
            num+= to_string(mapping[chint]);
        }
        return num;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            string q = mapped(s,mapping);
            int x = stoi(q);
            v.push_back({x,i});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto &it : v){
            int index = it.second;
            ans.push_back(nums[index]);
        }
        return ans;
    }
};