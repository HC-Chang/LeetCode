/*
 * @lc app=leetcode id=1046 lang=c
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
int getMax(int *stones, int stonesSize)
{
    int max = stones[0];
    int index = 0;
    for (int i = 1; i < stonesSize; i++)
    {
        if (max < stones[i])
        {
            max = stones[i];
            index = i;
        }
    }
    stones[index] = 0;
    return max;
}

void insert(int val, int *stones, int stonesSize)
{
    for (int i = 0; i < stonesSize; i++)
    {
        if (stones[i] == 0)
        {
            stones[i] = val;
            return;
        }
    }
}

int lastStoneWeight(int *stones, int stonesSize)
{
    // Solution 1:
    // get max val
    int m1;
    int m2;
    while (true)
    {
        m1 = getMax(stones, stonesSize);
        m2 = getMax(stones, stonesSize);

        if (m2 == 0)
        {
            return m1;
        }
        insert(m1 - m2, stones, stonesSize);
    }

    // Solution 2:
    // sort - 略

    // Solution 3:
    // count value - 略

    // Solution 4:
    // heap 最大堆
}
// @lc code=end
