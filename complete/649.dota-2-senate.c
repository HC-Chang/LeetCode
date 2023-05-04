/*
 * @lc app=leetcode id=649 lang=c
 *
 * [649] Dota2 Senate
 */

// @lc code=start
char *predictPartyVictory(char *senate)
{
    int s_len = strlen(senate);
    int mark = 0;
    int r_count = 0, d_count = 0;
    for (int i = 0; i < s_len; i++)
    {
        if (senate[i] == 'R')
            r_count++;
        else
            d_count++;
    }
    while (r_count > 0 && d_count > 0)
    {
        for (int i = 0; i < s_len; i++)
        {
            if (senate[i] == 'R')
            {
                if (mark++ < 0)
                {
                    senate[i] = '1';
                    r_count--;
                }
            }
            else if (senate[i] == 'D')
            {
                if (mark-- > 0)
                {
                    senate[i] = '1';
                    d_count--;
                }
            }
        }
    }
    return r_count > 0 ? "Radiant" : "Dire";
}
// @lc code=end

// Note : greedy