class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n = digits.size();
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                digits[i]++;
            }
            else{
                digits[i]+=carry;
                carry=0;
            } 
            if(digits[i]>=10){
                digits[i]%=10;
                carry++;
            }
        }
        if(carry!=0) digits.insert(digits.begin(),carry);
        return digits;
    }
};