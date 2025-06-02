/*
 * @lc app=leetcode id=135 lang=c
 *
 * [135] Candy
 */

// @lc code=start

#define MAX(a, b) a >= b ? a : b

// Speed up
static inline int sum(int *arr, int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        s += arr[i];
    }

    return s;
}

int candy(int *ratings, int ratingsSize)
{
    if (ratingsSize < 2)
    {
        return ratingsSize;
    }

    int *candies = calloc(ratingsSize, sizeof(int));
    int i;
    for (i = 0; i < ratingsSize; i++)
    {
        candies[i] = 1;
    }

    for (i = 1; i < ratingsSize ; ++i)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (i = ratingsSize - 1; i > 0; --i)
    {
        if (ratings[i] < ratings[i - 1])
        {
            candies[i - 1] = MAX(candies[i - 1], candies[i] + 1);
        }
    }

    int s = sum(candies, ratingsSize);
    free(candies);

    return s;
}
// @lc code=end

// Note: greedy