/*
 * @lc app=leetcode id=2825 lang=cpp
 *
 * [2825] Make String a Subsequence Using Cyclic Increments
 */

// @lc code=start
class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int n1 = str1.size();
        int n2 = str2.size();
        int s2 = 0;
        for (int s1 = 0; s1 < n1 && s2 < n2; s1++)
        {
            if (str1[s1] == str2[s2] || (str1[s1] + 1) % 26 == (str2[s2]) % 26)
                s2++;
        }

        return s2 == n2;
    }
};
// @lc code=end

// Note: two pointers