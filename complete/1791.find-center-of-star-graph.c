/*
 * @lc app=leetcode id=1791 lang=c
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
int findCenter(int **edges, int edgesSize, int *edgesColSize)
{
    int hash[100001] = {0};
    for (int i = 0; i < edgesSize; i++)
    {
        if (++hash[edges[i][0]] >= 2)
            return edges[i][0];
        if (++hash[edges[i][1]] >= 2)
            return edges[i][1];
    }
    return -1;
}
// @lc code=end

// Note: graph