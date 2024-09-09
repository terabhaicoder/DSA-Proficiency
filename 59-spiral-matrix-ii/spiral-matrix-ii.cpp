class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {{}};
        vector<vector<int>>ans(n,vector<int>(n,0));
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int values = 1;
        int dir = 0;

        while(top<=bottom && left<=right){
            //top
            if(dir==0){
            for(int i=left;i<=right;i++){
                ans[top][i] = values;
                values++;
            }
            top++;
        }
            //right 
            if(dir==1){
                for(int i=top;i<=bottom;i++){
                ans[i][right] = values;
                values++;
            }
            right--;
            }
            //bottom
            if(dir==2){
            for(int i=right;i>=left;i--){
                ans[bottom][i] = values;
                values++;
            }
            bottom--;
         }
         //left
         if(dir==3){
            for(int i=bottom;i>=top;i--){
                ans[i][left] = values;
                values++;
            }
            left++;
         }
         dir++;
         if(dir==4) dir=0;
        }
        return ans;

    }
};