/*
 * @lc app=leetcode id=2126 lang=c
 *
 * [2126] Destroying Asteroids
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

bool asteroidsDestroyed(int mass, int *asteroids, int asteroidsSize)
{
    qsort(asteroids, asteroidsSize, sizeof(int), sort);

    long long cur = mass;
    for (int i = 0; i < asteroidsSize; i++)
    {
        if (cur >= asteroids[i])
            cur += asteroids[i];
        else
            return false;
    }

    return true;
}
// @lc code=end

// Note: sort