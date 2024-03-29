/*
 * @lc app=leetcode id= lang=cpp
 *
 * [706] Desgin HashMap
 */

// @lc code=start
class MyHashMap {
    const static int maxn = 1e6;
    int mp[maxn + 1];
public:
    MyHashMap() {
        memset(mp, -1, sizeof(mp));
    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

