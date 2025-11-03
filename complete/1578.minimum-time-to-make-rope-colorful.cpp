/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size();
        int min_val = 0;
        int tmp_val;
        for (int i = 0; i < n; i++)
        {
            tmp_val = neededTime[i];
            while (i + 1 < n && colors[i] == colors[i + 1])
            {
                if (neededTime[i + 1] > tmp_val)
                {
                    min_val += tmp_val;
                    tmp_val = neededTime[i + 1];
                }
                else
                    min_val += neededTime[i + 1];

                i++;
            }
        }

        return min_val;
    }
};
// @lc code=end
