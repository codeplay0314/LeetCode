/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
class MonoStack {
public:
    void push(int h, int pre) {
        int size = vec.size();
        while (size && h >= vec[size - 1].h) {
            vec.pop_back();
            size--;
        }
        vec.push_back(Node(h, pre));
    }
    bool search(int h) {
        int l = 0, r = vec.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (vec[mid].pre >= h) l = mid + 1;
            else r = mid - 1;
        }
        if (l == vec.size()) return false;
        return vec[l].h > h;
    }
private:
    class Node {
    public:
        int h, pre;
        Node(int _h, int _pre) : h(_h), pre(_pre) {}
    };
    vector<Node> vec;
};

class Solution {
    const int inf = 1e9 + 1;
public:
    bool find132pattern(vector<int>& nums) {
        int pre_min = inf;
        MonoStack mst;
        for (auto num : nums) {
            if (mst.search(num)) return true;
            mst.push(num, pre_min);
            pre_min = min(pre_min, num);
        }
        return false;
    }
};
// @lc code=end

