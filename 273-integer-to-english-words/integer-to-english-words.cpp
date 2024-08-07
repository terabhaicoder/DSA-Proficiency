class Solution {
public:
        vector<string> below10 ={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        vector<string> below20={"Ten","Eleven","Twelve","Thirteen",  "Fourteen", "Fifteen","Sixteen", "Seventeen", "Eighteen", "Nineteen"};
                      
        vector<string> below100 ={"","",   "Twenty",  "Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};


    string helper(int num){ 

        string ans = "";

        if(num<10)  {
            ans=below10[num];
        }
        else if(num<20){
            ans=below20[num-10];
        }
        else if(num<100){
            ans= below100[num/10];
            if(num%10 >0 ){
                ans+=" "+helper(num%10);
            }
        }
        else if(num <1000){
            ans = helper(num/100) + " Hundred";
            if(num % 100 >0){
                ans+=" "+ helper(num%100);
            } 
        }
        else if(num <1000000){
            ans = helper(num/1000) + " Thousand";
            if (num%1000 > 0) {
                ans += " " + helper(num%1000);
            }
            
        }
        else if(num < 1000000000){
                ans = helper(num/1000000) + " Million";
        
             if (num % 1000000 > 0) {
                ans += " " + helper(num % 1000000);
            }
        }
        else {
            ans= helper(num/1000000000) + " Billion " + helper(num%1000000000);
        }

        if(ans.size()!=0 && ans[ans.size()-1]==' '){
            ans.pop_back();      
        }

        return ans;

    }

    string numberToWords(int num) {

        if(num==0) return "Zero";
        return helper(num);
    }
};