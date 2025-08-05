/*
 * @lc app=leetcode id=3477 lang=c
 *
 * [3477] Fruits Into Baskets II
 */

// @lc code=start
int numOfUnplacedFruits(int *fruits, int fruitsSize, int *baskets, int basketsSize)
{
    int cnt = 0;
    for (int i = 0; i < fruitsSize; i++)
    {
        for (int j = 0; j < fruitsSize; j++)
        {
            if (fruits[i] <= baskets[j])
            {
                baskets[j] = 0;
                cnt--;
                break;
            }
        }
    }

    return fruitsSize + cnt;
}
// @lc code=end

// Note: simulation
