295. Find Median from Data Stream
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        large.push(-num);
        small.push(-large.top());
        large.pop();
        if(large.size()<small.size()){
            large.push(-small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if(large.size()>small.size()){
            return -large.top();
        }
        else{
            return (small.top()-large.top())/2.0;
        }
    }
private:
    priority_queue<long> small, large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */