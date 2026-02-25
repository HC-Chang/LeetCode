/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int aa = __builtin_popcount(a);
            int bb = __builtin_popcount(b);
            if (aa == bb)
                return a < b;
            return aa < bb;
        });

        return arr;
    }
};
// @lc code=end
