class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string original = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(original==endWord) return steps;
            for(int i=0;i<original.size();i++){
                string word = original;
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
            }
        }
        return 0; 
    }
};