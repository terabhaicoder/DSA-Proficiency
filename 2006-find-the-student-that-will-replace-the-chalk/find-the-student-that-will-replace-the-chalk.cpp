class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int ans = -1;
        int n = chalk.size();
        int i=0;
        int sum=0;
        //for(int j=0;j<n;j++) sum+=chalk[j];
        //k = k % sum;
        while(true){
            if(k<chalk[i%n]) return i%n;
            else{
                k-=chalk[i%n];
                if(i<n) sum+=chalk[i];
                i++;
            }
            if(i==n){
                k = k%sum;
            }
        }
        return 0;
    }
};