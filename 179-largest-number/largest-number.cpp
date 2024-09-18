class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int i: nums){
            v.push_back(to_string(i));
        }
        sort(v.begin(), v.end(), [&](string a,  string b) {
            return a+b > b+a;
        });
        string result = "";
        for(string c: v){
            result+=c;
        }
        if(result[0] == '0') return "0";
        return result;
    }
};