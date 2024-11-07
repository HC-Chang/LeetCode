/*
 * @lc app=leetcode id=2275 lang=cpp
 *
 * [2275] Largest Combination With Bitwise AND Greater Than Zero
 */

// @lc code=start
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int max_cnt = 0; 
        int cnt;
        for (int i = 0; i < 24; i++) {
            cnt = 0; 
            for (auto c : candidates) {
                if ((c & (1 << i)) != 0)
                    cnt++;
            }
            max_cnt = max(max_cnt, cnt);
        } 
        return max_cnt;
    }
};
// @lc code=end

// Note: bit manipulation