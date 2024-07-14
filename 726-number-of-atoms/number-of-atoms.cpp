class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack< unordered_map<string,int> >st;
        st.push(unordered_map<string,int>());
        int i=0;
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i]==')'){
                unordered_map<string,int>curr = st.top();
                st.pop();
                i++;
                string mult="";
                while(i<n && isdigit(formula[i])){
                    mult.push_back(formula[i]);
                    i++;
                }
                if(!mult.empty()){
                    int multint  = stoi(mult);
                for(auto &it : curr){
                    string elem = it.first;
                    int count = it.second;
                    curr[elem] = count*multint; 
                }
                }
                for(auto &it : curr){
                    string elem = it.first;
                    int count = it.second;
                    st.top()[elem] += count; 
                }
            }
            else{
                string currelem = "";
                currelem.push_back(formula[i]);
                i++;
                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    currelem.push_back(formula[i]);
                    i++;
                }
                string currcount= "";
                while(i<n && isdigit(formula[i])){
                    currcount.push_back(formula[i]);
                    i++;
                }
                int countint = currcount.empty() ? 1 : stoi(currcount);
                st.top()[currelem] += countint;
            }
        }
        map<string,int>sortedmap(st.top().begin(),st.top().end());
        string result="";
        for(auto &it: sortedmap){
            string elem = it.first;
            result+=elem;
            int count  = it.second;
            if(count>1) result+= to_string(count);
        }
        return result;

    }
};