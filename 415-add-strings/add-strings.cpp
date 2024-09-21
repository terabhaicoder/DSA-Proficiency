class Solution {
public:
    char addChar(char a , char b , int &carry){
        char ans = carry+a+b-48;
        if(ans>57){
            carry=1;
            ans -= 10;
            return ans;
        }
        else{
            carry=0;
            return ans;
        }
    }
    string addStrings(string num1, string num2) {
        int inum1=num1.length()-1;
        int inum2=num2.length()-1;
        int carry = 0;
        string ans;
        while(true){
            if(inum1>=0 && inum2>=0){
                char ch = addChar(num1[inum1],num2[inum2],carry);
                ans.push_back(ch);
                inum1--;
                inum2--;
            }
            else if(inum1>=0){
                char ch = addChar(num1[inum1],'0',carry);
                ans.push_back(ch);
                inum1--;
            }
            else if(inum2>=0){
                char ch = addChar('0',num2[inum2],carry);
                ans.push_back(ch);
                inum2--;
            }
            else if(carry>0){
                ans.push_back(carry+48);
                carry = 0;
            }
            else{
                break;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};