/*
 * @lc app=leetcode id= lang=cpp
 *
 * [705] Desgin HashSet
 */

// @lc code=start
class MyHashSet {
    const static int maxn = 1e6;
    bool exist[maxn + 1];
public:
    MyHashSet() {
        memset(exist, 0, sizeof(exist));
    }
    
    void add(int key) {
        exist[key] = true;
    }
    
    void remove(int key) {
        exist[key] = false;
    }
    
    bool contains(int key) {
        return exist[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

