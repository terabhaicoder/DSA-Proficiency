class MedianFinder {
public:
    priority_queue<int>maxhheap;
    priority_queue<int,vector<int>,greater<int> >minhheap;
    MedianFinder() {
        
    }
    void addNum(int num) {
        if(maxhheap.empty() || maxhheap.top()>num) maxhheap.push(num);
        else minhheap.push(num);

        if(maxhheap.size() > 1 + minhheap.size()) {
            minhheap.push(maxhheap.top());
            maxhheap.pop();
        }
        else if(maxhheap.size() + 1 <minhheap.size()){
            maxhheap.push(minhheap.top());
            minhheap.pop();
        }
    }
    
    double findMedian() {
       if(maxhheap.size() == minhheap.size()){ 
        if(maxhheap.empty()) return 0;
        double mean = (maxhheap.top() + minhheap.top())/2.0;
         return mean;
       }
       else {
			return maxhheap.size() > minhheap.size() ? maxhheap.top() : minhheap.top();
		}
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */