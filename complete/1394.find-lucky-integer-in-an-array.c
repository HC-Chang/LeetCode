/*
 * @lc app=leetcode id=1394 lang=c
 *
 * [1394] Find Lucky Integer in an Array
 */

// @lc code=start
int sort(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int findLucky(int *arr, int arrSize)
{
    qsort(arr, arrSize, sizeof(int), sort);

    int cnt = 1;
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i - 1] == arr[i])
            cnt++;
        else
        {
            if (arr[i - 1] == cnt)
                return cnt;
            cnt = 1;
        }
    }
    if (arr[arrSize - 1] == cnt)
        return cnt;
    return -1;
}
// @lc code=end

// Note: hash table + counting

// Gemini Solution:

// int findLucky(int *arr, int arrSize)
// {
//     int counts[501] = {0};
//     for (int i = 0; i < arrSize; i++)
//         counts[arr[i]]++;
//
//     for (int i = 500; i >= 1; i--)
//     {
//         if (counts[i] == i)
//             return i;
//     }
//
//     return -1;
// }
