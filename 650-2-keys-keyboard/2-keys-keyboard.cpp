class Solution {
public:
    int t[1001][1001];
    int solve(int curr,int copy,int n){
        if(curr==n) return 0;

        if(curr>n) return 1e9;
        if(t[curr][copy]!=-1) return t[curr][copy];
        int copyallpaste = 1 + 1 + solve(curr*2,curr,n);
        int paste = 1 + solve(curr + copy,copy,n);

        return t[curr][copy] = min(paste,copyallpaste);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        memset(t,-1,sizeof(t));
        return 1 + solve(1,1,n);
    }
};