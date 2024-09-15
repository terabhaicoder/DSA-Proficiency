class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mp;
        vector<int> state(5, 0); 
        string currentState = "00000";  
        mp[currentState] = -1;
    
        int maxLength = 0;
    
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') state[0] ^= 1;
            else if (s[i] == 'e') state[1] ^= 1; 
            else if (s[i] == 'i') state[2] ^= 1; 
            else if (s[i] == 'o') state[3] ^= 1; 
            else if (s[i] == 'u') state[4] ^= 1; 
            currentState = "";
            for (int j = 0; j < 5; ++j) {
                currentState += to_string(state[j]);
            }
            if (mp.find(currentState) != mp.end()) {
           
                maxLength = max(maxLength, i - mp[currentState]);
            } else {
                mp[currentState] = i;
            }
        }

        return maxLength;
    }
};