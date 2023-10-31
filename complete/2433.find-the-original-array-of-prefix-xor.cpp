/*
 * @lc app=leetcode id=2433 lang=cpp
 *
 * [2433] Find The Original Array of Prefix Xor
 */
// @lc code=start
class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        vector<int> r(pref.size());
        r[0] = pref[0];
        for (int i = 1; i < pref.size(); i++)
            r[i] = pref[i - 1] ^ pref[i];
        return r;
    }
};
// @lc code=end

// Note: bit manipulation