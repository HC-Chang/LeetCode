/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 */

// @lc code=start
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1000000007;
        int res = 0;
        unordered_map<int, int> h;
        for (int i : nums) {
            int temp = i, j = 0;
            while (temp > 0) {
                j = j * 10 + temp % 10;
                temp /= 10;
            }
            res = (res + h[i - j]) % MOD;
            h[i - j]++;
        }
        return res;
    }
};
// @lc code=end

// Official Solution

// Note: hash table