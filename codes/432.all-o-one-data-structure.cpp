/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
class AllOne {
    unordered_map<string, int> cnt;
    priority_queue<pair<int, string>> maxHeap;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> minHeap;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        cnt[key]++;
        maxHeap.push({cnt[key], key});
        minHeap.push({cnt[key], key});
    }
    
    void dec(string key) {
        cnt[key]--;
        maxHeap.push({cnt[key], key});
        minHeap.push({cnt[key], key});
    }
    
    string getMaxKey() {
        while (!maxHeap.empty()) {
            auto cur = maxHeap.top();
            if (cnt[cur.second] != cur.first || !cur.first) {
                maxHeap.pop();
                continue;
            }
            return cur.second;
        }
        return "";
    }
    
    string getMinKey() {
        while (!minHeap.empty()) {
            auto cur = minHeap.top();
            if (cnt[cur.second] != cur.first || !cur.first) {
                minHeap.pop();
                continue;
            }
            return cur.second;
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

