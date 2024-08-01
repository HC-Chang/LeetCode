/*
 * @lc app=leetcode id=2678 lang=cpp
 *
 * [2678] Number of Senior Citizens
 */

// @lc code=start
class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int senior_cnt = 0;
        for (auto s : details)
        {
            if (s[11] > '6' ||
                (s[11] == '6' && s[12] > '0'))
                senior_cnt++;
        }
        return senior_cnt;
    }
};
// @lc code=end
