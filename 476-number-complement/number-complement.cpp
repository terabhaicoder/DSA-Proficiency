class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int count = 0;
        while(num != 0){
            num >>= 1;
            count++;
        }
        int mask = pow(2, count) - 1;
        return mask ^ temp;
    }

};