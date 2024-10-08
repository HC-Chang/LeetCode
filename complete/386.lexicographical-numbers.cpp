/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        int cur = 1;

        for (int i = 0; i < n; ++i)
        {
            ans.push_back(cur);

            if (cur * 10 <= n)
                cur *= 10;
            else
            {
                while (cur % 10 == 9 || cur >= n)
                    cur /= 10;
                cur += 1;
            }
        }

        return ans;
    }
};
// @lc code=end

// Note: DFS + trie