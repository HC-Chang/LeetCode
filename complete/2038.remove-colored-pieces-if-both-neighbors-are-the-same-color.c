/*
 * @lc app=leetcode id=2038 lang=c
 *
 * [2038] Remove Colored Pieces if Both Neighbors are the Same Color
 */

// @lc code=start
bool winnerOfGame(char *colors)
{
    int len = strlen(colors);
    if (len < 3)
        return false;
    int cnt[2] = {0};
    int tmp = 1;
    char c = colors[0];
    for (int i = 1; i < len; i++)
    {
        if (colors[i] == c)
            tmp++;
        else
        {
            if (tmp > 2)
            {
                if (c == 'B')
                    cnt[1] += tmp - 2;
                else
                    cnt[0] += tmp - 2;
            }
            tmp = 1;
            c = colors[i];
        }
    }
    if (tmp > 2)
    {
        if (c == 'B')
            cnt[1] += tmp - 2;
        else
            cnt[0] += tmp - 2;
    }
    return cnt[0] > cnt[1];
}
// @lc code=end
