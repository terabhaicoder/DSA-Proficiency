typedef pair<long long,long long>P;
class Solution {
public:
 
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n+1];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<long long>ways(n,0);
        vector<long long>dist(n,LLONG_MAX);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        long long mod = (long long)(1e9 + 7);
        while(!pq.empty()){
            long long dis  = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                long long adjnode = it.first;
                long long wt = it.second;
                if(wt+dis < dist[adjnode]){
                    dist[adjnode] = wt+dis;
                    pq.push({wt+dis,adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(wt+dis==dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }

            }
        }
        return ways[n-1]%mod;

    }
};