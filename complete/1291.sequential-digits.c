/*
 * @lc app=leetcode id=1291 lang=c
 *
 * [1291] Sequential Digits
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Solution 2:
int check_position(int val)
{
    int r = 1;

    while (val)
    {
        if (val / 10)
            ++r;
        val /= 10;
    }
    return r;
}

int find_start(int p)
{
    return (123456789 / pow(10, 9 - p));
}

int *sequentialDigits(int low, int high, int *returnSize)
{
    int *ans = calloc(45, sizeof(int));
    *returnSize = 0;
    int p = check_position(low);
    int start = find_start(p);
    int offset = 0;
    for (int i = 0; i < p; i++)
        offset += pow(10, i);
    p++;

    while (start <= high)
    {
        if (start >= low)
            ans[(*returnSize)++] = start;
        start += offset;
        if (start % 10 == 0)
        {
            start = (123456789 / pow(10, 9 - p));
            offset += pow(10, p - 1);
            p++;
        }
    }
    return ans;
}
// @lc code=end

// Note: enumeration

// Solution 1:
// int* sequentialDigits(int low, int high, int* returnSize) {
//     int arr[]={1,2,3,4,5,6,7,8,9,\
//                     12,23,34,45,56,67,78,89, \
//                     123,234,345,456,567,678,789, \
//                     1234,2345,3456,4567,5678,6789, \
//                     12345,23456,34567,45678,56789, \
//                     123456,234567,345678,456789, \
//                     1234567, 2345678, 3456789,
//                     12345678,23456789, \
//                     123456789};
//     int *ans = malloc(45*sizeof(int));
//     * returnSize = 0;
//     for(int i = 0; i<45; i++)
//     {
//         if(arr[i]>high)
//             break;
//         if(arr[i] >= low)
//             ans[(*returnSize)++] = arr[i];
//     }
//     return ans;
// }