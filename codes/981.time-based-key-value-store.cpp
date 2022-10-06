/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
    map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        auto node = mp.find(key);
        if (node == mp.end()) return "";
        auto& vec = node->second;
        int l = 0, r = vec.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (vec[mid].first <= timestamp) l = mid + 1;
            else r = mid - 1;
        }
        return r >= 0 ? vec[r].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

