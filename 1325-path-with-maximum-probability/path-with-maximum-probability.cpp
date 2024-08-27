class Solution {
public: 
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n, vector<pair<int, double>>());
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            double cost = succProb[i];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
           
        }

        vector<double> dist(n, 0.0);

        priority_queue<pair<double, int>> pq;

        pq.push({1.0, start_node});
        dist[start_node] = 1.0;

        while(!pq.empty()){
            int currNode = pq.top().second;
            double cost = pq.top().first;
            pq.pop();


            for(int i=0; i<adj[currNode].size(); i++){
                int neighbour = adj[currNode][i].first;
                double neighCost = adj[currNode][i].second;

                if(dist[neighbour]<dist[currNode]*neighCost){
                    dist[neighbour] = dist[currNode]*neighCost;
                    pq.push({dist[neighbour], neighbour});
                }
            }

        }

        if(dist[end_node]==0) return 0;
        return dist[end_node];
    }
};