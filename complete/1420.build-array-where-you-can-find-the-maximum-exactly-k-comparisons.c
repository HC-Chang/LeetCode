/*
 * @lc app=leetcode id=1420 lang=c
 *
 * [1420] Build Array Where You Can Find The Maximum Exactly K Comparisons
 */

// @lc code=start
int mod = 1e9 + 7;
int mem[51][101][51] = {0};
int numOfArrays(int n, int m, int k)
{
    if (k < 1 || k > m || k > n)
        return 0;
    if (n == 1 && k == 1)
        return m;
    if (mem[n][m][k])
        return mem[n][m][k];
    long r = 0;
    for (int i = 1; i <= m; ++i)
    {
        r += numOfArrays(n - 1, m, k);
        r += numOfArrays(n - 1, i - 1, k - 1);
        r -= numOfArrays(n - 1, i - 1, k);
        r = (r + mod) % mod;
    }
    mem[n][m][k] = r;
    return mem[n][m][k];
}
// @lc code=end

// Note: DP + prefix sum