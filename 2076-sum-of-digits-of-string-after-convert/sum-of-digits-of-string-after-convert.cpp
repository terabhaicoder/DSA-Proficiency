class Solution {
public:
    int getLucky(string s, int k) {
        int num =0;
        for(auto it: s){
            int n = it - 'a' + 1;
            auto [q, r]=div(n, 10);
            num+=q+r;
        }
        if(k==1) return num;
        k--;
       for(int x=num; x>=10 && k>0; k--){
            for(num=0; x>0; ){
                auto [q, r]=div(x, 10);
                num+=r;
                x=q;
            }
            x=num;
        }
        return num; 
    }
};