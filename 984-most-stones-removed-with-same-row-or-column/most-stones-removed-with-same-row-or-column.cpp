class Solution {
public:
    int find_parent(int node,vector<int>& parent){
        if(node == parent[node])
            return node;
        
        return parent[node] = find_parent(parent[node],parent);
    }
    
    void union_find(int u,int v,vector<int>& parent,vector<int>& rank){
        u = find_parent(u,parent);
        v = find_parent(v,parent);
        
        if(parent[u] == parent[v])
            return;
        
        if(rank[u] < rank[v]){
            parent[u] = v;
        }else if(rank[v] < rank[u]){
            parent[v] = u;
        }else{
            parent[v] = u;
            rank[u] = rank[u] + 1;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> parent(n,0);
        vector<int> rank(n,0);
        
        for(int i=0;i<n;i++)
            parent[i] = i;
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    union_find(i,j,parent,rank);
                }
            }
        }
        // return component size - 1 for every component
        
        for(int i=0;i<n;i++)
            find_parent(i,parent);
        
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++){
            m[parent[i]]++;
        }
        
        int ans=0;
        for(auto a:m){
            ans += (a.second-1);
        }
        
        return ans;
    }
};