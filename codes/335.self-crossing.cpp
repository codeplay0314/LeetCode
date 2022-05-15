/*
 * @lc app=leetcode id=335 lang=cpp
 *
 * [335] Self Crossing
 */

// @lc code=start
class Solution {
    const int inf = ~0u>>1;
    const int move[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    inline int trans(int x) {
        return x % 4;
    }
    inline bool reached(int x, int offset, int lim) {
        if (offset > 0) return x + offset >= lim;
        else return x + offset <= lim;
    }
    bool trapped = false;
    int traps[4] = {inf, inf, inf, inf};
    int pos[2] = {0, 0}, pre[2] = {0, 0};
public:
    bool isSelfCrossing(vector<int>& distance) {
        if (distance.size() < 4) return false;
        int cur = -1, dim = 0;
        int bounds[4][2][2] = {{{-inf, inf}, {-inf, inf}}, {{inf, -inf}, {inf, -inf}}, {{inf, inf}, {-1, 0}}, {{0, distance[0]}, {1, 0}}};
        for (int dis : distance) {
            cur = trans(cur + 1);
            dim ^= 1;
            int offset = move[cur][dim] * dis;
            if (trapped) {
                if (reached(pos[dim], offset, traps[cur])) {
                    return true;
                }
                pos[dim] += offset;
                traps[trans(cur + 3)] = pos[dim^1];
            } else {
                if (!reached(pos[dim], offset, bounds[cur][0][0])) {
                    traps[trans(cur + 1)] = bounds[cur][0][1];
                    trapped = true;
                } else if (!reached(pos[dim], offset, bounds[cur][1][0])) {
                    traps[trans(cur + 1)] = bounds[cur][1][1];
                    trapped = true;
                }
                pre[dim] = pos[dim];
                pos[dim] += offset;
                bounds[cur][0][0] = pre[dim];
                bounds[trans(cur + 2)][0][1] = pos[dim^1];
                bounds[trans(cur + 2)][1][0] = pre[dim] - move[cur][dim];
                bounds[trans(cur + 3)][1][1] = pre[dim];
                traps[trans(cur + 3)] = pos[dim^1];
            }
        }
        return false;
    }
};
// @lc code=end
