/*
 * @lc app=leetcode id=657 lang=c
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
bool judgeCircle(char *moves)
{
    int cnt[2] = {0};
    while (*moves)
    {
        switch (*moves++)
        {
        case 'R':
            ++cnt[0];
            break;
        case 'L':
            --cnt[0];
            break;
        case 'U':
            ++cnt[1];
            break;
        case 'D':
            --cnt[1];
            break;
        }
    }

    return cnt[0] == 0 && cnt[1] == 0;
}
// @lc code=end
