/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
    vector<int> arr;
    unordered_map<int, int> pos;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (pos.find(val) != pos.end()) {
            return false;
        }
        pos[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (pos.find(val) == pos.end()) {
            return false;
        }
        int p = pos[val];
        arr[p] = arr[arr.size() - 1];
        arr.pop_back();
        pos[arr[p]] = p;
        pos.erase(val);
        return true;
        
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

