/*
 * @lc app=leetcode id=2058 lang=c
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *nodesBetweenCriticalPoints(struct ListNode *head, int *returnSize)
{
    int *arr = malloc(100000 * sizeof(int));
    int idx = 0;
    struct ListNode *cur = head;
    while (cur)
    {
        arr[idx++] = cur->val;
        cur = cur->next;
    }

    *returnSize = 2;
    int c_idx = 0;
    for (int i = 1; i < idx - 1; i++)
    {
        if ((arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) || (arr[i] < arr[i + 1] && arr[i] < arr[i - 1]))
            arr[c_idx++] = i;
    }

    if (c_idx < 2)
    {
        arr[0] = -1;
        arr[1] = -1;
        return arr;
    }
    int min = INT_MAX;
    int max = arr[c_idx - 1] - arr[0];
    for (int i = 0; i < c_idx - 1; i++)
        min = fmin(min, arr[i + 1] - arr[i]);
    arr[0] = min;
    arr[1] = max;
    return arr;
}
// @lc code=end

// Note: linked list