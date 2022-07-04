# Solution for the codestudio problem = https://www.codingninjas.com/codestudio/problems/min-heap_4691801

class Heap {
    
private:
    vector<int> A;
    int size;
    
    void minHeapify(int i){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;
        
        if(l <= size && A[l] < A[i])
            smallest = l;
        
        if(r <= size && A[r] < A[smallest])
            smallest = r;
        
        if(smallest != i){
            swap(A[i], A[smallest]);
            minHeapify(smallest);
        }
    }
    
public:
    Heap(){
        size = 0;
    }
    
    int pop(){
        if(size <= 0)
            return -1;
        
        int minVal = A[0];
        A[0] = A[size - 1];
        A.pop_back();
        
        size -= 1;
        
        minHeapify(0);
        return minVal;
    }
    
    void push(int val){
        A.push_back(val);
        size += 1;
        
        int i = size - 1;
        while(i > 0 && A[(i - 1) / 2] > A[i]){
            swap(A[(i - 1) / 2], A[i]);
            i = (i - 1) / 2;
        }
    }
};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> res;
    Heap h = Heap();
    
    for(auto it : q){
        if(it[0] == 0){
            h.push(it[1]);
        }
        else{
            res.push_back(h.pop());
        }
    }
    
    return res;
}
