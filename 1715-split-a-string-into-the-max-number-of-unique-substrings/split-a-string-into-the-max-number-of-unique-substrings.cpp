class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_map<string, bool>mp;
        int c = back(s, 0, mp);
        return c;
    }
    int back(string s, int pos, unordered_map<string, bool>& mp) {
        int r = 0;
        if (pos >= s.size())
            return 0;
        for(int i = pos; i < s.size(); i++) {
            string a = s.substr(pos, i - pos + 1);
            if (mp.find(a) != mp.end())
                continue;
            mp[a] = 1;
            int comb = 1 + back(s, i + 1, mp);
            mp.erase(a);
            r = max(r, comb);
        }
        return r;
    }
};