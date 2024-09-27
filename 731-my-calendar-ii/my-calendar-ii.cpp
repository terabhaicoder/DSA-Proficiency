class MyCalendarTwo {
public:    
    vector<pair<int,int>> cal;
    vector<pair<int,int>> temp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
       for(auto [tempFirst,tempSecond]:temp){
        if(max(start,tempFirst)<min(end,tempSecond))
         return false;
       }
       for(auto [first,second]:cal){
        if(max(start,first)<min(end,second)){
            temp.push_back({max(start,first),min(end,second)});
        }
       }
       cal.push_back({start,end});
       return true;
    }

};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */