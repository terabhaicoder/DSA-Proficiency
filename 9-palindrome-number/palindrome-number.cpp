class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long div=1;
        while(x>=10*div){
            div*=10;
        }
        while(x!=0){
            int left = x%10;
            int right = x/div;
            if(left!=right) return false;
            x = (x%div)/10;
            div = div/100;
        }
        return true;
    }
};