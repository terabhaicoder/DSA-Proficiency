class Solution {
public:
typedef pair<int,string> p;
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<p,vector<p> >pq;
        int n = names.size();
        for(int i=0;i<n;i++){
            pq.push({heights[i],names[i]});
        }
        vector<string>ans;
        while(!pq.empty()){
            auto it  = pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};