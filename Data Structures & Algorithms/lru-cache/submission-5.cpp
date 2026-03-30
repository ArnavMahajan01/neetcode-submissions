class LRUCache {
public:
    int cap;
    list<pair<int,int>> lru;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
      if(mp.find(key) == mp.end()) return -1;

      auto it = mp[key];
      int val = it->second;
      
      lru.erase(it);
      lru.push_front({key, val});
      mp[key] = lru.begin();

      return val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            lru.erase(mp[key]);
        }else if(lru.size() == cap){
          auto last = lru.back();
            mp.erase(last.first);
            lru.pop_back();
        }
        lru.push_front({key, value});
        mp[key] = lru.begin();
    }
};
