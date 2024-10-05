/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int s1_len = s1.size();
        int s2_len = s2.size();
        if (s1_len > s2_len)
            return false;
        int count[26] = {0};
        for (int i = 0; i < s1_len; i++)
            count[s1[i] - 'a']++;
        for (int i = 0, j = 0; j < s2_len; ++j)
        {
            if (--count[s2[j] - 'a'] < 0)
            {
                while (s2[i] != s2[j])
                    count[s2[i++] - 'a']++;
                count[s2[i++] - 'a']++;
            }
            if (j - i + 1 == s1_len)
                return true;
        }

        return false;
    }
};
// @lc code=end
