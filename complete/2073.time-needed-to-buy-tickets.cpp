/*
 * @lc app=leetcode id=2073 lang=cpp
 *
 * [2073] Time Needed to Buy Tickets
 */

// @lc code=start
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();
        int sec = 0;
        bool keep = true;
        while (keep)
        {
            for (int i = 0; i < n; i++)
            {
                if (tickets[i] > 0)
                {
                    --tickets[i];
                    sec++;
                }
                if (i == k && tickets[i] == 0)
                {
                    keep = false;
                    break;
                }
            }
        }

        return sec;
    }
};
// @lc code=end

// Note: queue