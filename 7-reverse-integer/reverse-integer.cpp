class Solution {
public:
    int reverse(int x) {

        
        int revdigit = 0; // THIS IS THE ANSWER TO RETURN 
        while(x!=0)
        {   // THIS IS THE CONDITON OF REVERSING A LONG LONG INT NUMBER
            if(revdigit >INT_MAX/10 || revdigit<INT_MIN/10) return 0;
           
          revdigit = revdigit*10 + x%10;  // THE FORMULA TO REVERSE THE NUMBER
           x = x/10;
        }
    return revdigit;
    }
};