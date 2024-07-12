/*
 * @lc app=leetcode id=1717 lang=cpp
 *
 * [1717] Maximum Score From Removing Substrings
 */

// @lc code=start
class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        char c1 = 'a';
        char c2 = 'b';
        if (x < y)
        {
            swap(x, y);
            swap(c1, c2);
        }

        int ans = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (auto c : s)
        {
            if (c == c1)
                cnt1++;
            else if (c == c2)
            {
                if (cnt1)
                {
                    ans += x;
                    cnt1--;
                }
                else
                    cnt2++;
            }
            else
            {
                ans += min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }
        ans += min(cnt1, cnt2) * y;
        return ans;
    }
};
// @lc code=end

// Note: stack + greedy