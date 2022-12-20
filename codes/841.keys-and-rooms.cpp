/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        int sum = 1;
        visited[0] = true;
        for (int key : rooms[0]) q.push(key);
        while (!q.empty()) {
            int r = q.front();
            q.pop();
            if (!visited[r]) {
                sum++;
                visited[r] = true;
                for (int key : rooms[r]) q.push(key);
            }
        }
        return sum == n;
    }
};
// @lc code=end

