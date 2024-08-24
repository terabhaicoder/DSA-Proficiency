class Solution {
public:
    void dfs(int node, vector<vector<int>>&ans, vector<int>&v,vector<int>adj[],int target){
        v.push_back(node);
        if(node==target){
            ans.push_back(v);
        }
        else {
             for(auto it: adj[node]){
                dfs(it,ans,v,adj,target);
            
        }
    }
    v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                int u = i;
                int v = graph[i][j];
                adj[u].push_back(v);
            }
        }
        vector<vector<int>>ans;
        vector<int>v;
        dfs(0,ans,v,adj,n-1);
        return ans;
    }
};