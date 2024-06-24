/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = position.back();

        auto count = [&](int f) {
            int prev = position[0];
            int cnt = 1;
            for (int& curr : position) {
                if (curr - prev >= f) {
                    prev = curr;
                    cnt++;
                }
            }
            return cnt;
        };

        int mid;
        while (l < r) {
            mid = (l + r + 1) >> 1;
            if (count(mid) >= m)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
// @lc code=end

// Note: binary search + sorting