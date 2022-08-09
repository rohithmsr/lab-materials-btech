// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
    int size;
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    
public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if(size % 2 == 0){
            minq.push(num);
            ++size;
            
            maxq.push(minq.top());
            minq.pop();
        }
        else{
            maxq.push(num);
            ++size;
            
            minq.push(maxq.top());
            maxq.pop();
        }
    }
    
    double findMedian() {
        if(size == 0)
            return -1;
        
        if(size % 2 == 1){
            return maxq.top();
        }
        return (minq.top() + maxq.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
