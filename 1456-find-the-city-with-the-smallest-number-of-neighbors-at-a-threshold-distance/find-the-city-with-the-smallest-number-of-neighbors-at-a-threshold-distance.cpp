class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,INT_MAX));
	    
	    for(auto i:edges){
            matrix[i[0]][i[1]]=i[2];
            matrix[i[1]][i[0]]=i[2];
        }

        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }
	    
	    for(int v=0;v<n;v++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(matrix[i][v]==INT_MAX || matrix[v][j]==INT_MAX){
	                    continue;
	                }
	                matrix[i][j]=min(matrix[i][j],matrix[i][v]+matrix[v][j]);
	            }
	        }
	    }
    
            int ans=n+1;
            int fans=-1;
	    	for(int i=0;i<n;i++){
                int cnt=0;
                for(auto j:matrix[i]){
                    if(j<=distanceThreshold){
                        cnt++;
                    }
                }
                if(cnt<=ans){
                    ans=cnt;
                    fans=i;
                }
	    }
        return fans;
    }
};