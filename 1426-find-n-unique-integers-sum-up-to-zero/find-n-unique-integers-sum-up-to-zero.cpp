class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>v;
        if(n%2!=0) {
            v.push_back(0);
            n--;
        }
        while(n>0){
            v.push_back(n);
            v.push_back(-1*n);
            n-=2;
        }
        return v;

    }
};