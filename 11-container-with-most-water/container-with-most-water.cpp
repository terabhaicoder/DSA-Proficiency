class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int sum=0,ans=0;
        while(l<r){
            if(height[l]<height[r]){
                sum = height[l] * (r-l);
                l++;
            }
            else{
                sum = height[r] * (r-l);
                r--;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};