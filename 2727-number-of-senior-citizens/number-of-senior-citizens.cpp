class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(int i=0;i<details.size();i++){
            int first = details[i][11]-'0';
            int second = details[i][12]-'0';

            if(first==6 && second >=1) cnt++;
            else if(first>6) cnt++;
        }
        return cnt;
    }
};