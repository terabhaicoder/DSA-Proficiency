class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        int n = prerequisites.size();
        vector<int>indegree(numCourses,0);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(cnt==numCourses) return true;
        else return false;
    }
};
