/*
 * @lc app=leetcode id=2064 lang=c
 *
 * [2064] Minimized Maximum of Products Distributed to Any Store
 */

// @lc code=start
bool can_distribute(int x, int *quantities, int quantitiesSize, int n)
{
    int j = 0;
    int remaining = quantities[j];

    for (int i = 0; i < n; i++)
    {
        if (remaining <= x)
        {
            j++;
            if (j == quantitiesSize)
                return true;
            else
                remaining = quantities[j];
        }
        else
            remaining -= x;
    }
    return false;
}

int minimizedMaximum(int n, int *quantities, int quantitiesSize)
{
    int left = 0;
    int right = INT_MIN;
    for (int i = 0; i < quantitiesSize; i++)
    {
        if (quantities[i] > right)
            right = quantities[i];
    }

    int middle;
    while (left < right)
    {
        middle = (left + right) / 2;
        if (can_distribute(middle, quantities, quantitiesSize, n))
            right = middle;
        else
            left = middle + 1;
    }
    return left;
}
// @lc code=end

// Note: binary search

// Official Solution