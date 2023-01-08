/*
 * @lc app=leetcode id=134 lang=c
 *
 * [134] Gas Station
 */

// @lc code=start
int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
    int start = 0;
    int target_station_sum = 0;
    int total_gas = 0;

    for (int i = 0; i < gasSize; i++)
    {
        target_station_sum += gas[i] - cost[i];
        total_gas += gas[i] - cost[i];

        if (target_station_sum < 0)
        {
            target_station_sum = 0;
            start = i + 1;
        }
    }

    if (total_gas < 0)
        return -1;
    return start;
}
// @lc code=end

// Ref:
// https://hannahpun.gitbook.io/leetcode-note/array/134-gas-station