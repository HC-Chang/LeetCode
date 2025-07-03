/*
 * @lc app=leetcode id=3304 lang=cpp
 *
 * [3304] Find the K-th Character in String Game I
 */

// @lc code=start
class Solution
{
public:
    char kthCharacter(int k)
    {
        if (k == 1)
            return 'a';
        string s = "a";
        while (s.size() < k)
        {
            string tmp = s;
            for (auto &c : tmp)
            {
                if (c == 'z')
                    c = 'a';
                else
                    c += 1;
            }
            s = tmp + s;
        }
        return s[s.size() - k];
    }
};

// @lc code=end

// Note: bit manipulation + simulation + recursion