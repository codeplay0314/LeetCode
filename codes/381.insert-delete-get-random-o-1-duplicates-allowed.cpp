/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

// @lc code=start
class RandomizedCollection {
    int size = 0;
    unordered_map<int, set<int>> mp;
    vector<int> nums;
public:
    RandomizedCollection() {
        srand(time(0));
    }
    
    bool insert(int val) {
        set<int>& pos = mp[val];
        nums.push_back(val);
        pos.insert(size++);
        return pos.size() == 1;
    }
    
    bool remove(int val) {
        set<int>& pos = mp[val];
        cout << pos.size() << endl;
        if (pos.size() == 0) return false;
        int p = *(pos.begin());
        int sub = nums[p] = nums[--size];
        nums.pop_back();
        pos.erase(p);
        mp[sub].erase(size);
        if (size != p) mp[sub].insert(p);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % size];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

