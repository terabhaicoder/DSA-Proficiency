class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>>mpp,string src,string dest,unordered_set<string>&vis,double product,double &ans){
        if(vis.find(src)!=vis.end()) return;
        vis.insert(src);

        if(src==dest){
            ans = product;
            return;
        }
        for(auto &it: mpp[src]){
                string u = it.first;
                double v = it.second;
            dfs(mpp,u,dest,vis,product*v,ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
       unordered_map<string,vector<pair<string,double>>>mpp;
       for(int i=0;i<n;i++){
        string u = equations[i][0];
        string v = equations[i][1];
        double val = values[i];

        mpp[u].push_back({v,val});
        mpp[v].push_back({u,1.0/val});
       }
       vector<double> result;
       for( auto &it: queries){
        string src = it[0];
        string dest = it[1];

        double ans = -1.0;
        double product = 1.0;
       
        if(mpp.find(src)!=mpp.end()){
             unordered_set<string>vis;
            dfs(mpp,src,dest,vis,product,ans);
        }
        result.push_back(ans);
       }
       return result;

    }
};