class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        stack<string>st;
        string token="";
        while(getline(ss,token,'/')){
           if(token=="" || token==".") continue;
          if(token!="..") st.push(token); 
           else if(!st.empty())st.pop();
        }
        string result="";
        if(st.empty()) return "/";
        while(!st.empty()){
            result = "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
};