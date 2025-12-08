/*
 * @lc app=leetcode id=1925 lang=c
 *
 * [1925] Count Square Sum Triples
 */

// @lc code=start
int countTriples(int n)
{
    int cnt = 0;
    int cache[n + 1];
    for (int i = 1; i <= n; i++)
        cache[i] = i * i;

    for (int k = 5; k <= n; k++)
    {
        for (int i = 3; i <= k; i++)
        {
            for (int j = 3; j <= k; j++)
            {
                if (cache[i] + cache[j] == cache[k])
                    cnt++;
            }
        }
    }
    return cnt;
}
// @lc code=end

// Note: math + enumeration