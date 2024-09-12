class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st;
        for(auto it : allowed) st.insert(it);

        int count = 0;
        for(int i=0;i<words.size();i++){

            string a = words[i];
            int flag = 1;
            for(int j=0;j<a.size();j++){
                if(st.find(a[j])==st.end()) {
                    flag = 0;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};