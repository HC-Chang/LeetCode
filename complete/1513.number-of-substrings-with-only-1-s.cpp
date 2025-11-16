/*
 * @lc app=leetcode id=1513 lang=cpp
 *
 * [1513] Number of Substrings With Only 1s
 */

 // @lc code=start
class Solution {
public:
    const long long mod = 1e9 + 7;
    int numSub(string s) {

        long long cnt = 0;
        long long tmp = 0;
        for (auto& c : s)
        {
            if (c == '1')
                tmp++;
            else
            {
                cnt += ((1 + tmp) * (tmp) / 2) % mod;
                tmp = 0;
            }
        }

        cnt += ((1 + tmp) * (tmp) / 2) % mod;
        return cnt;
    }
};
// @lc code=end

// Note: math