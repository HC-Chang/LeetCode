/*
 * @lc app=leetcode id=646 lang=c
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    int **x = (int **)a;
    int **y = (int **)b;
    return x[0][1] - y[0][1];
}

int findLongestChain(int **pairs, int pairsSize, int *pairsColSize)
{
    qsort(pairs, pairsSize, sizeof(int *), sort);

    int last = INT_MIN;
    int count = 0;
    for (int i = 0; i < pairsSize; i++)
    {
        if (pairs[i][0] > last)
        {
            count++;
            last = pairs[i][1];
        }
    }

    return count;
}
// @lc code=end

// Note: DP . greedy . sorting