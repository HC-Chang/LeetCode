/*
 * @lc app=leetcode id=1481 lang=c
 *
 * [1481] Least Number of Unique Integers after K Removals
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int findLeastNumOfUniqueInts(int *arr, int arrSize, int k)
{
    qsort(arr, arrSize, sizeof(int), sort);
    int cnts[arrSize];
    int idx = 0;
    int cnt = 1;
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] == arr[i - 1])
            cnt++;
        else
        {
            cnts[idx++] = cnt;
            cnt = 1;
        }
    }
    cnts[idx++] = cnt;
    qsort(&cnts, idx, sizeof(int), sort);
    int i = 0;
    for (i = 0; i < idx; i++)
    {
        if (k <= cnts[i])
            break;
        k -= cnts[i];
    }
    if (k == cnts[i])
        i++;

    return idx - i;
}
// @lc code=end

// Note: hash table + sorting + counting