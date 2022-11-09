/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
    static const int maxp = 1e5;
    stack<int> prices, dates;
    int date = 0;
public:
    StockSpanner() {
        prices.push(maxp + 1);
        dates.push(-1);
    }
    
    int next(int price) {
        while (price >= prices.top()) {
            prices.pop();
            dates.pop();
        }
        int res = date - dates.top();
        prices.push(price);
        dates.push(date++);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

