/*
 * @lc app=leetcode id=2326 lang=c
 *
 * [2326] Spiral Matrix IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **spiralMatrix(int m, int n, struct ListNode *head, int *returnSize,
                   int **returnColumnSizes)
{
    int visited[m][n];
    memset(visited, 0, sizeof(visited));

    int **ans = malloc(m * sizeof(int *));
    *returnSize = m;
    returnColumnSizes[0] = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        ans[i] = malloc(n * sizeof(int));
        returnColumnSizes[0][i] = n;
    }

    if (!head)
        return ans;
    ans[0][0] = head->val;
    head = head->next;
    visited[0][0] = 1;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir_idx = 0;
    int pos[2] = {0, 0};
    int next_pos[2];
    int idx = 1;
    while (head)
    {
        while (
            (pos[0] + dir[dir_idx][0] < 0) || (pos[0] + dir[dir_idx][0] >= m) ||
            (pos[1] + dir[dir_idx][1] < 0) || (pos[1] + dir[dir_idx][1] >= n) ||
            visited[pos[0] + dir[dir_idx][0]][pos[1] + dir[dir_idx][1]] == 1)
            dir_idx = (dir_idx + 1) % 4;
        pos[0] += dir[dir_idx][0];
        pos[1] += dir[dir_idx][1];

        ans[pos[0]][pos[1]] = head->val;
        visited[pos[0]][pos[1]] = 1;
        head = head->next;
        idx++;
    }
    while (idx < m * n)
    {
        while (
            (pos[0] + dir[dir_idx][0] < 0) || (pos[0] + dir[dir_idx][0] >= m) ||
            (pos[1] + dir[dir_idx][1] < 0) || (pos[1] + dir[dir_idx][1] >= n) ||
            visited[pos[0] + dir[dir_idx][0]][pos[1] + dir[dir_idx][1]] == 1)
            dir_idx = (dir_idx + 1) % 4;
        pos[0] += dir[dir_idx][0];
        pos[1] += dir[dir_idx][1];

        ans[pos[0]][pos[1]] = -1;
        visited[pos[0]][pos[1]] = 1;
        idx++;
    }
    return ans;
}
// @lc code=end

// Note: array + linked list + matrix