class Solution {
public:
    using ll=long long;
    ll maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<ll> main(n);
        ll ans=0;
        for(int i=0;i<n;i++){
            main[i]=(ll)points[0][i];
            ans=max(ans,main[i]);
        }
        for(int i=1;i<m;i++){
            vector<ll> left(n);
            vector<ll> right(n);
            for(int j=0;j<n;j++){
                if(j>0){
                    left[j]=max(left[j-1]-1,main[j]);
                } else {
                    left[j]=main[j];
                }

                int k=n-j-1;
                if(k<n-1){
                    right[k]=max(right[k+1]-1,main[k]);
                } else {
                    right[k]=main[k];
                }
            }

            for(int j=0;j<n;j++){
                main[j]=points[i][j]+max(left[j],right[j]);
                if(i==m-1){
                    ans=max(ans,main[j]);
                }
            }
        }
        return ans;
    }
};