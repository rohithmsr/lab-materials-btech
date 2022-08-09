https://leetcode.com/problems/lru-cache/

struct DLNode {
    int key;
    int val;
    DLNode* prev;
    DLNode* next;
    
    DLNode(int k, int v){
        key = k;
        val = v;
    }
};

class LRUCache {

private:
    map<int, DLNode*> cache;
    
    int size;
    int capacity;
    
    DLNode* head;
    DLNode* tail;
    
    void addNode(DLNode* node){
        node->prev = head;
        node->next = head->next;
        
        node->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLNode* node){
        DLNode* pre = node->prev;
        DLNode* nex = node->next;
        
        pre->next = nex;
        nex->prev = pre;
        delete node;
    }
    
    DLNode* moveNode(DLNode* node){
        int k = node->key;
        int v = node->val;
        
        removeNode(node);
        
        DLNode* newNode = new DLNode(k, v);
        addNode(newNode);
        
        return newNode;
    }
    
    int popTail(){
        DLNode* res = tail->prev;
        int k = res->key;
        
        removeNode(res);
        
        return k;
    }
    
public:
    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        
        head = new DLNode(0, 0);
        head->prev = NULL;
        
        tail = new DLNode(-1, -1);
        tail->next = NULL;
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        
        DLNode* node = cache[key];
        int val = node->val;
        
        cache[key] = moveNode(node);
        
        return val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            DLNode* node = cache[key];
            node->val = value;
            
            cache[key] = moveNode(node);
            return;
        }
        
        DLNode* newNode = new DLNode(key, value);
        
        cache[key] = newNode;
        addNode(newNode);
        
        ++size;
        
        if(size > capacity)
        {
            int key = popTail();
            cache.erase(key);
            --size;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
