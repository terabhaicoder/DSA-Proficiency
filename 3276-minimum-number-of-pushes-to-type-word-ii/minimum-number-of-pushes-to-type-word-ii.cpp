class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int times = 8;
        int multiplier = 1;
        int ans =0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            else{
                ans= ans + (multiplier*freq[i]);
                times--;

                if(times==0){
                    times=8;
                    multiplier++;
                }
            }
        }
        return ans;
    }
};