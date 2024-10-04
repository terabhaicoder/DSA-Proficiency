class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long n = skill.size();
        if(n==2) return skill[0]*skill[1];
        bool flag = false;
        long long i=1,j=n-2;
        long long comp = skill[0]+skill[n-1];
        long long total = skill[0]*skill[n-1];
        while(i<=j){
            long long sum = skill[i]+skill[j];
            if(comp==sum){
                total+=skill[i]*skill[j];
                i++;
                j--;
            }
            else{
                flag = true;
                break;
            }
        }
        if(flag) return -1;
        return total;
    }
};