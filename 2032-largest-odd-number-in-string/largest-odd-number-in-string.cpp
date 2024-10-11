class Solution {
public:
    string largestOddNumber(string num) {
        
        int x = 0;
        for(int i=num.size()-1;i>=0;i--){
            int x = num[i] - '0';
            if(x!=0 && x%2!=0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};