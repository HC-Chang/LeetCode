/*
 * @lc app=leetcode id=1578 lang=c
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
int minCost(char *colors, int *neededTime, int neededTimeSize)
{
    int sum = neededTime[0];
    int tmp_max = neededTime[0];
    int min_cost = 0;
    for (int i = 1; i < neededTimeSize; i++)
    {
        if (colors[i] == colors[i - 1])
        {
            sum += neededTime[i];
            if (neededTime[i] > tmp_max)
                tmp_max = neededTime[i];
        }
        else
        {
            min_cost += sum - tmp_max;
            sum = neededTime[i];
            tmp_max = neededTime[i];
        }
    }
    if (colors[neededTimeSize - 1] == colors[neededTimeSize - 2])
        min_cost += sum - tmp_max;

    return min_cost;
}
// @lc code=end
