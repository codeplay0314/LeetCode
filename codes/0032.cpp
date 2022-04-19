class StackNode {
public:
    int level, pos;
};

class MonoStack {
private:
    vector<StackNode> st;
    int len = 0;
public:
    int size() {
        return len;
    }
    StackNode find(int x) {
        return st[x];
    }
    void pop() {
        st.pop_back();
        len--;
    }
    void push(StackNode node) {
        while (len > 0 && st[len - 1].level > node.level) pop();
        if (len == 0 || st[len - 1].level != node.level) {
            st.push_back(node);
            len++;
        }
    }
};

class Solution {
private:
    MonoStack st;
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        for (int i = 0, lev = 0, len = s.size(); i < len; i++) {
            if (s[i] == '(') {
                lev++;
                st.push((StackNode){lev, i});                
            } else {
                int l = 0, r = st.size() - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (st.find(mid).level <= lev) l = mid + 1;
                    else r = mid - 1;
                }
                if (r >= 0) ans = max(ans, i - st.find(r).pos + 1);
                lev--;
            }
        }
        return ans;
    }
};