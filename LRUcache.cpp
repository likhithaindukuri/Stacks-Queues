class LRUCache {
public:
queue<int> LRU;
    vector<int> usages = vector<int>(10001, 0);
    vector<int> kvp = vector<int>(10001, -1);
    int size = 0;
    int cap = 0;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(kvp[key] != -1){
            LRU.push(key);
            usages[key]++;
        }
        return kvp[key];
    }
    
    void put(int key, int value) {
        if(size < cap || kvp[key] != -1){
            if(kvp[key] == -1) size++;
            LRU.push(key);
            usages[key]++;
            kvp[key] = value;
            return;
        }
        while(usages[LRU.front()] != 1){
            usages[LRU.front()]--;
            LRU.pop();
        }
        kvp[LRU.front()] = -1;
        usages[LRU.front()]--;
        LRU.pop();
        LRU.push(key);
        usages[key]++;
        kvp[key] = value;
    }
};