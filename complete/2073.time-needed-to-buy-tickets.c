/*
 * @lc app=leetcode id=2073 lang=c
 *
 * [2073] Time Needed to Buy Tickets
 */

// @lc code=start
int timeRequiredToBuy(int *tickets, int ticketsSize, int k)
{
    int sec = 0;
    bool keep = true;
    while (keep)
    {
        for (int i = 0; i < ticketsSize; i++)
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
// @lc code=end

// Note: queue