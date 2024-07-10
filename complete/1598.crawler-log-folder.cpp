/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int cnt = 0;
        for (auto s : logs)
        {
            if (s == "../")
            {
                if (cnt > 0)
                    cnt--;
            }
            else if (s == "./")
                continue;
            else
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end
