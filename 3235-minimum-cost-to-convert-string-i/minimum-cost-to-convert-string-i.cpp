class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<int>>adj(26,vector<int>(26,INT_MAX));
        for(int i=0;i<26;i++){
            adj[i][i]=0;
        }
        for(int i=0;i<cost.size();i++){
            int src=original[i]-'a';
            int dest=changed[i]-'a';
            adj[src][dest]=min(adj[src][dest],cost[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX){
                        adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                
                    }
                }
            }
        }
        long long totalcost=0;
        for(int i=0;i<source.size();i++){
            int src=source[i]-'a';
            int dest=target[i]-'a';
            if(src !=dest){
                if(adj[src][dest]==INT_MAX){
                    return -1;
                }
                totalcost+=adj[src][dest];
            }
        }
        return totalcost;


    }
};