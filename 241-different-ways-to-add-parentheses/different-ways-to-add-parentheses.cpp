class Solution {
private:
    vector<int> solve(string expression){
        int n = expression.size();
        vector<int> ans;
        bool isNumber = true;
        for(auto& it: expression){
            if(!isdigit(it)){
                isNumber = false;
                break;
            }
        }
        if(isNumber) {
            ans.push_back(stoi(expression)); 
            return ans;
        }
        for(int i = 0; i < n; i++){
            bool isAddition = (expression[i] == '+');
            bool isSubtraction = (expression[i] == '-');
            bool isMultiplication = (expression[i] == '*');
            if(isAddition || isSubtraction || isMultiplication){
                vector<int> left = solve(expression.substr(0, i));
                vector<int> right = solve(expression.substr(i+1));
                for(auto& it: left){
                    for(auto& iit: right){
                        if(expression[i] == '+') ans.push_back(it + iit);
                        else if(expression[i] == '-') ans.push_back(it - iit);
                        else ans.push_back(it * iit);
                    }
                }
            }
        }
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans = solve(expression);
        return ans;
    }
};