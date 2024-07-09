/*
 * @lc app=leetcode id=1701 lang=c
 *
 * [1701] Average Waiting Time
 */

// @lc code=start
double averageWaitingTime(int **customers, int customersSize,
                          int *customersColSize)
{
    double wait = 0;
    double curr = 0;

    for (int i = 0; i < customersSize; i++)
    {
        curr = fmax(curr, customers[i][0]) + customers[i][1];
        wait += curr - customers[i][0];
    }

    return wait / customersSize;
}
// @lc code=end

// Note: simulation