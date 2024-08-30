class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(const int n, vector<vector<int>>& edges, int const source, int const destination, int const target) {
        unordered_map<int,int> parent;
        vector<int> dist(n, INT_MAX);
        auto djkstra = [&dist, &edges, &parent, n, source, destination, target](bool flipnegative = false)
        {
            unordered_map<int, vector<pair<int,int>>> al;
            for(auto const& e: edges) {
                al[e[0]].emplace_back(e[1], e[2]);
                al[e[1]].emplace_back(e[0], e[2]);
            }
            vector<bool> visited(n);
            priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq; // (dist, node)
            pq.emplace(0, source);
            parent[source] = -1;
            while(!pq.empty()) {
                auto [d, i] = pq.top();
                pq.pop();
                if(d > dist[i]) continue;
                visited[i] = true;
                if(i == destination) break;
                for(auto [j, w] : al[i]) {
                    if(flipnegative && w < 0) w = -w;
                    if(w > 0 && !visited[j] && d + w < dist[j]) {
                        pq.emplace( (dist[j] = d + w), j );
                        parent[j] = i;
                    }
                }
            }
            return dist[destination];
        };
        
        // regular dist ignoring negative edges
        if(int d = djkstra();  d < target)
            return {};
        else if(d == target) {
            for(auto & e : edges) {
                if(e[2] == -1)
                    e[2] = 1000000005;
            }
            return edges;
        }
        
        // flip negative edges to search distance
        while(true) {
            parent.clear();
            fill(dist.begin(), dist.end(), INT_MAX);
            int dif = target - djkstra(true);
            
            if(dif < 0) return {};
            if(dif == 0) {
                for(auto & e : edges) {
                    if(e[2] < 0)
                        e[2] = -e[2];
                }
                return edges;
            }

            unordered_map<int,int> path;
            for(int prev = destination,  cur = parent[prev] ; cur != -1; prev = cur, cur = parent[cur]) {
                path[prev] = cur;
            }

            bool done = false;
            for(auto & e : edges) {
                if(e[2] < 0) {
                    if(!done && (path.count(e[0]) && path[e[0]] == e[1] ||  path.count(e[1]) && path[e[1]] == e[0]) ) {
                        e[2] -= dif;
                        done = true;
                    }
                }
            }
        }
        return {};
    }
};