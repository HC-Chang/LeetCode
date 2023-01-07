/*
 * @lc app=leetcode id=134 lang=c
 *
 * [134] Gas Station
 */

// @lc code=start
int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
    int start = 0;
    int sum = 0;
    int total = 0;

    for (int i = 0; i < gasSize; i++)
    {
        total += gas[i] - cost[i];
        sum += gas[i] - cost[i];

        if (sum < 0)
        {
            sum = 0;
            start = i + 1;
        }
    }

    if (total < 0)
        return -1;
    return start;
}
// @lc code=end

// Ref:
// https://hannahpun.gitbook.io/leetcode-note/array/134-gas-station