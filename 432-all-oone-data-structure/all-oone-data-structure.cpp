class AllOne {
public:
    unordered_map<string,int> count;  
    set<pair<int,string>> se;         
    
    AllOne() {
        count.clear(); 
    }

    void inc(string key) {
        int n = count[key];  
        count[key]++;        
        se.erase({n, key});   
        se.insert({n+1, key}); 
    }

    void dec(string key) {
        int n = count[key];  
        count[key]--;        
        se.erase({n, key});   
        if (count[key] > 0) se.insert({n-1, key});  
        else count.erase(key); 
    }

    string getMaxKey() {
        if (!se.empty()) return se.rbegin()->second;  // Last element gives the maximum
        return "";
    }

    string getMinKey() {
        if (!se.empty()) return se.begin()->second;  // First element gives the minimum
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */