class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st;
        for(int i=0;i<bank.size();i++){
            st.insert(bank[i]);
        }
        unordered_set<string>visited;
        queue<string>q;
        int level = 0;
        q.push(startGene);
        visited.insert(startGene);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();;
                q.pop();
                if(curr == endGene) return level;

                 for(char ch : "ACGT"){
                    for(int i=0;i<curr.length();i++){
                        string neighbour = curr;
                        neighbour[i] = ch;

                        if(visited.find(neighbour)==visited.end() && st.find(neighbour)!=st.end()){
                            q.push(neighbour);
                            visited.insert(neighbour);
                        }
                    }
                 } 
            }
            level++;
        }
        return -1;
    }
};