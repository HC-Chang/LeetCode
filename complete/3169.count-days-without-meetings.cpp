/*
 * @lc app=leetcode id=3169 lang=cpp
 *
 * [3169] Count Days Without Meetings
 */

// @lc code=start
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        int cnt = 0;
        int l = 0;
        int r = 0;
        for (auto m : meetings)
        {
            if (r >= m[0])
                l = r;
            else
            {
                if (m[0] - r > 1)
                    cnt += m[0] - r - 1;
                l = m[0];
            }
            if (m[1] > r)
                r = m[1];
        }

        return cnt += days - r;
    }
};
// @lc code=end

// Note: sorting