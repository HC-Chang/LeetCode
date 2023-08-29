/*
 * @lc app=leetcode id=2483 lang=c
 *
 * [2483] Minimum Penalty for a Shop

 */

// @lc code=start
int bestClosingTime(char *customers)
{
    int y_total = 0;
    int len = strlen(customers);
    for (int i = 0; i < len; i++)
    {
        if (customers[i] == 'Y')
            y_total++;
    }

    int t = 0;
    int min = INT_MAX;
    int y_count = 0;
    int n_count = 0;
    int penalty;
    for (int i = 0; i <= len; i++)
    {
        penalty = n_count + y_total - y_count;
        if (penalty < min)
        {
            min = penalty;
            t = i;
        }
        if (i == len)
            continue;
        if (customers[i] == 'Y')
            y_count++;
        else
            n_count++;
    }
    return t;
}
// @lc code=end

// Note: prefix sum
