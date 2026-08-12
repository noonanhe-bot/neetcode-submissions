class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> cache_;
    list<int> order;
    int capacity_;
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (cache_.find(key) != cache_.end()) {
            // if we find the key we need to update it's position in the list
            // by first erasing it's position in the list
            order.erase(cache_[key].second);
            order.push_back(key); // then pushing the key to the back
            cache_[key].second = --order.end(); // and updating the pointer
            return cache_[key].first;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache_.find(key) != cache_.end()) {
            // if we find the key we need to update it's position in the list
            // by first erasing it's position in the list
            order.erase(cache_[key].second);
        }else if (cache_.size() == capacity_) {
            int lru = order.front();
            cache_.erase(lru);
            order.pop_front();
        } 
        order.push_back(key);
        cache_[key] = {value, --order.end()};
    }
};
