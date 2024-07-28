class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        priority_queue<pair<int , int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
        pq.push({0 , 1});
        vector<vector<int>> adj(n+1);
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> wt(n+1 , INT_MAX);
        wt[0] = 1;
        int cnt = 0;
        vector<int>freq(n+1 , 0);
        freq[1] = 1;
        while(pq.size())
        {
            int t = pq.top().first;
            int node1 = pq.top().second;
            pq.pop();
            freq[node1]++;
            int x = t/change;
            if(x%2==1)
            {
                int wait = ((x+1) * change) - t;
                t=t+wait;
            }
            for(auto node2 : adj[node1])
            {
                if(freq[node2] <= 2 && t+time != wt[node2])
                {
                    wt[node2] = t+time;
                    if(node2 == n)
                    {
                        cnt++;
                        if(cnt == 2)
                        {
                            return wt[n];
                        }
                    }
                    pq.push({t+time , node2});
                }
               
            }
        }
        return 0 ;
    }
};