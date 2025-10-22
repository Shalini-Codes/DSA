#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int capacity;
    list<pair<int, int>> cache; // stores {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key -> iterator in list

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        // Move the accessed key to the front (most recently used)
        auto it = mp[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        // If key exists, remove it from current position
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }
        // If capacity full, remove least recently used (from back)
        else if (cache.size() == capacity) {
            auto lru = cache.back();
            mp.erase(lru.first);
            cache.pop_back();
        }

        // Insert key-value at front (most recently used)
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */