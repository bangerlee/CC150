class LRUCache {
private:
    int m_capacity;
    map<int,list<pair<int,int>>::iterator> m_mp;
    list<pair<int,int>> m_l;
public:
    LRUCache(int capacity) {
        m_capacity=capacity;
    }
    
    int get(int key) {
        auto it=m_mp.find(key);
        if(it==m_mp.end()) return -1;
        m_l.splice(m_l.begin(),m_l,it->second);
        return m_l.begin()->second;
    }
    
    void put(int key, int value) {
        auto it=m_mp.find(key);
        if(it!=m_mp.end()){
            it->second->second=value;
            m_l.splice(m_l.begin(),m_l,it->second);
            return;
        }
        if(m_l.size()==m_capacity){
            auto tmp=m_l.back();
            m_mp.erase(tmp.first);
            m_l.pop_back();
        }
        m_l.emplace_front(key,value);
        m_mp[key]=m_l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
