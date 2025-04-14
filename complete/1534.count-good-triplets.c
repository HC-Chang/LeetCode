/*
 * @lc app=leetcode id=1534 lang=c
 *
 * [1534] Count Good Triplets
 */

// @lc code=start
int countGoodTriplets(int *arr, int arrSize, int a, int b, int c)
{
    int cnt = 0;
    for (int i = 0; i < arrSize - 2; i++)
    {
        for (int j = i + 1; j < arrSize - 1; j++)
        {
            if (abs(arr[i] - arr[j]) > a)
                continue;
            for (int k = j + 1; k < arrSize; k++)
            {
                if (abs(arr[j] - arr[k]) > b)
                    continue;
                if (abs(arr[i] - arr[k]) <= c)
                    ++cnt;
            }
        }
    }
    return cnt;
}
// @lc code=end
