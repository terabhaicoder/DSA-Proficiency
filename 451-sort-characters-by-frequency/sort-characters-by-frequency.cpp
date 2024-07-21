class Solution {
public:
    typedef pair<char,int> P;
    struct lambda{
        bool operator()(P &p1, P &p2){
            return p2.second>p1.second;
        }
    };
    string frequencySort(string s) {
        priority_queue<P,vector<P>,lambda>pq;
        unordered_map<char,int>mpp;
        for(auto &it: s){
            mpp[it]++;
        }
        for(auto &it: mpp){
            pq.push({it.first,it.second});
        }
        string res="";
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            res+=string(temp.second,temp.first);
        }
        return res;
    }
};