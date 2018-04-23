// 295. Find Median from Data Stream
// 这题可以用两个堆来做，左边是大堆，右边是小堆，C++中priority_queue是一个max heap.
// 只要维护右边比左边始终相等或者多一就好了。
// trick是，每次都先插进新元素到右边的堆中，然后把右边堆的top插到左边的堆中，把右边的top pop一下，
// 后判断如果左边大的话，就把左边的top插到右边中，左边top pop一下。这样做的好处是，省了很多判断，又能保证左右两个堆在中间位置上是有序的。
// 还有一个trick是，可以使用-num插入到max heap中，实现min heap。最后取结果的时候取反就好了。

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