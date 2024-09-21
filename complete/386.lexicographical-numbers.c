/*
 * @lc app=leetcode id=386 lang=c
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *lexicalOrder(int n, int *returnSize)
{
    *returnSize = n;
    int *ans = malloc(n * sizeof(int));
    int idx = 0;
    int cur = 1;
    for (int i = 0; i < n; ++i)
    {
        ans[idx++] = cur;

        if (cur * 10 <= n)
            cur *= 10;
        else
        {
            while (cur % 10 == 9 || cur >= n)
                cur /= 10;
            cur += 1;
        }
    }

    return ans;
}
// @lc code=end

// Note: DFS + trie