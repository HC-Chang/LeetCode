/*
 * @lc app=leetcode id=2251 lang=c
 *
 * [2251] Number of Flowers in Full Bloom
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int binarySearch(const int *arr, int left, int right, int target)
{
    int res = right + 1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (arr[mid] >= target)
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}

int *fullBloomFlowers(int **flowers, int flowersSize, int *flowersColSize, int *people, int peopleSize, int *returnSize)
{
    int starts[flowersSize], ends[flowersSize];
    for (int i = 0; i < flowersSize; ++i)
    {
        starts[i] = flowers[i][0];
        ends[i] = flowers[i][1];
    }
    qsort(starts, flowersSize, sizeof(int), sort);
    qsort(ends, flowersSize, sizeof(int), sort);
    int *ans = malloc(peopleSize * sizeof(int));

    int l, r;
    for (int i = 0; i < peopleSize; ++i)
    {
        r = binarySearch(starts, 0, flowersSize - 1, people[i] + 1);
        l = binarySearch(ends, 0, flowersSize - 1, people[i]);
        ans[i] = r - l;
    }
    *returnSize = peopleSize;
    return ans;
}
// @lc code=end

// Note: hash table + binary search + sorting