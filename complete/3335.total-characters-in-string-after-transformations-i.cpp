/*
 * @lc app=leetcode id=3335 lang=cpp
 *
 * [3335] Total Characters in String After Transformations I
 */

// @lc code=start
class Solution
{
public:
    int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t)
    {
        vector<int> cnt(26);
        for (char ch : s)
        {
            ++cnt[ch - 'a'];
        }
        for (int round = 0; round < t; ++round)
        {
            vector<int> nxt(26);
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % mod;
            for (int i = 2; i < 26; ++i)
            {
                nxt[i] = cnt[i - 1];
            }
            cnt = move(nxt);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            ans = (ans + cnt[i]) % mod;
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table + math