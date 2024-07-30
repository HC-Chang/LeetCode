/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 */

// @lc code=start
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();
        int min_deletions = 0;
        int b_count = 0;

        for (auto c : s)
        {
            if (c == 'b')
                b_count++;
            else
                min_deletions = fmin(min_deletions + 1, b_count);
        }

        return min_deletions;
    }
};
// @lc code=end

// Note: DP / stack