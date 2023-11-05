/*
 * @lc app=leetcode id=1535 lang=c
 *
 * [1535] Find the Winner of an Array Game
 */

// @lc code=start
int getWinner(int *arr, int arrSize, int k)
{
    if (arrSize == 1)
        return arr[0];
    if (k == 1)
        return fmax(arr[0], arr[1]);

    int win_count = 0;

    for (int i = 1; i < arrSize && win_count < k; ++i)
    {
        if (arr[i] > arr[0])
        {
            arr[0] = arr[i];
            win_count = 1;
        }
        else
            ++win_count;
    }

    return arr[0];
}
// @lc code=end
