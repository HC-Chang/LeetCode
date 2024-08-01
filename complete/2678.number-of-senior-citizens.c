/*
 * @lc app=leetcode id=2678 lang=c
 *
 * [2678] Number of Senior Citizens
 */

// @lc code=start
int countSeniors(char **details, int detailsSize)
{
    int senior_cnt = 0;
    for (int i = 0; i < detailsSize; i++)
    {
        if (details[i][11] > '6' || (details[i][11] == '6' && details[i][12] > '0'))
            senior_cnt++;
    }
    return senior_cnt;
}
// @lc code=end
