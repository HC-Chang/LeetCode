/*
 * @lc app=leetcode id=997 lang=c
 *
 * [997] Find the Town Judge
 */

// @lc code=start
int findJudge(int n, int **trust, int trustSize, int *trustColSize)
{
    int *count = calloc(n + 1, sizeof(int));
    
    for (int i = 0; i < trustSize; i++)
    {
        count[trust[i][0]]--;
        count[trust[i][1]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (count[i] == n - 1)
        {
            free(count);
            return i;
        }
    }
    
    free(count);
    return -1;
}
// @lc code=end

// 有向圖
// outdegree: -- (相信)
// indegree:  ++ (被相信)

// 法官:   不相信任何人 (outdegree = 0, indegree = n-1)
// 所有人: 信任法官

// trust [][a, b]: a 相信 b
// -> a--
// -> b++