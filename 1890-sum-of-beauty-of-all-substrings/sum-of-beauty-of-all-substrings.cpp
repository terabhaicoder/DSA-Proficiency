class Solution {
public:
    int ans = 0;
    int beautySum(string s) {
        
        for (int i = 0; i < s.length(); i++) {
            map<char, int> mp;
            for (int j = i; j < s.length(); j++) {
                mp[s[j]]++;
                int leastFrequent = INT_MAX;
                int mostFrequent = INT_MIN;
                for (auto it : mp) {
                    leastFrequent = min(leastFrequent, it.second);
                    mostFrequent = max(mostFrequent, it.second);
                }
                ans += mostFrequent - leastFrequent;
            }
        }

        return ans;
    }
};