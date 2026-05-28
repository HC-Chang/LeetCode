/*
 * @lc app=leetcode id=3121 lang=cpp
 *
 * [3121] Count the Number of Special Characters II
 */

// @lc code=start
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        vector<int> v(26);
        for (auto &c : word)
        {
            if (!isupper(c))
            {
                if (v[c - 'a'] <= 1)
                    v[c - 'a'] = 1;
                else
                    v[c - 'a'] = 3;
            }
            else
            {
                if (v[c - 'A'] == 1 || v[c - 'A'] == 2)
                    v[c - 'A'] = 2;
                else
                    v[c - 'A'] = 3;
            }
        }

        int cnt = 0;
        for (auto &vv : v)
        {
            if (vv == 2)
                cnt++;
        }

        return cnt;
    }
};

// @lc code=end

// Note: hash table