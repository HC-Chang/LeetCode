/*
 * @lc app=leetcode id=2924 lang=c
 *
 * [2924] Find Champion II
 */

// @lc code=start
int findChampion(int n, int **edges, int edgesSize, int *edgesColSize)
{
    int indegree[n];
    memset(indegree, 0, sizeof(indegree));

    for (int i = 0; i < edgesSize; i++)
        indegree[edges[i][1]]++;

    int champ = -1;
    int champCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            champCount++;
            champ = i;
        }
    }

    return champCount > 1 ? -1 : champ;
}
// @lc code=end

// Note: graph

// Official Solution