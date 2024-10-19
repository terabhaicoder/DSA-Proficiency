class Solution {
public:
    string solve(int n, int idx, string &s){
        // Base case: when we have reached the desired level n
        if(idx == n){
            return s; // return the final string at level n
        }
        
        // Create the reversed and inverted version of current string s
        string rev = "";
        for(auto c : s){
            if(c == '0') rev += to_string(1); // Invert 0 to 1
            else rev += to_string(0); // Invert 1 to 0
        }
        reverse(rev.begin(), rev.end()); // Reverse the string
        
        // Concatenate to form the next level string
        string temp = s + "1" + rev;
        
        // Recursively build the string for the next index level
        return solve(n, idx + 1, temp);
    }
    
    char findKthBit(int n, int k) {
        string s = "0"; // Start with S1 = "0"
        string res = solve(n, 1, s); // Build the string for level n
        return res[k - 1]; // Return the (k-1)-th character (zero-indexed)
    }
};