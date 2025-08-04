/*
 * @lc app=leetcode id=904 lang=c
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
int totalFruit(int *fruits, int fruitsSize)
{
    if (fruitsSize <= 2)
        return fruitsSize;
    int total = 0;
    int vals[2];
    for (int i = 0; i < fruitsSize - 1; i++)
    {
        vals[0] = fruits[i];
        int j = i + 1;
        while (j + 1 < fruitsSize && fruits[j] == vals[0])
            j++;
        vals[1] = fruits[j];

        while (j + 1 < fruitsSize && (fruits[j + 1] == vals[0] || fruits[j + 1] == vals[1]))
            j++;
        total = fmax(total, j - i + 1);
        if (total > fruitsSize / 2)
            break;
    }

    return total;
}
// @lc code=end

// Note: hash table + sliding window