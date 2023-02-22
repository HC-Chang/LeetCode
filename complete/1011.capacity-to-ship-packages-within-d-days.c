/*
 * @lc app=leetcode id=1011 lang=c
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
bool check(int *weights, int weightsSize, int middle, int days)
{
    int count = 0;
    int j;
    int sum;
    for (int i = 0; i < weightsSize;)
    {
        j = i;
        sum = 0;
        while (j < weightsSize && sum + weights[j] <= middle)
        {
            sum += weights[j];
            j++;
        }
        count += 1;
        if (count > days)
            return false;
        i = j;
    }
    return true;
}

int shipWithinDays(int *weights, int weightsSize, int days)
{
    int left = INT_MIN;
    int right = 0;
    int middle;
    for (int i = 0; i < weightsSize; i++)
    {
        if (left < weights[i])
            left = weights[i];
        right += weights[i];
    }

    while (left < right)
    {
        middle = left + (right - left) / 2;
        if (check(weights, weightsSize, middle, days))
            right = middle;
        else
            left = middle + 1;
    }

    return left;
}
// @lc code=end
