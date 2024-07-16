class Solution {
public:
    int solve(int n){
        int num = 0;
        while(n>0){
            int digit = n%10;
            num = num + digit*digit;
            n=n/10;
        }
        return num;
    }
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n!=1 && s.find(n)==s.end()){
            s.insert(n);
            n = solve(n);
        }
        return n==1;
    }
};