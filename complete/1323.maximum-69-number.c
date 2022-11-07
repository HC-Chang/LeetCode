/*
 * @lc app=leetcode id=1323 lang=c
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
int maximum69Number(int num)
{
    // Solution 1:
    int arr[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        arr[i] = num % 10;
        num /= 10;
    }
    for (int i = 3; i >= 0; i--)
    {
        if (arr[i] != 9 && arr[i] != 0)
        {
            arr[i] = 9;
            break;
        }
    }
    return arr[0] + 10 * arr[1] + 100 * arr[2] + 1000 * arr[3];

    // Solution 2:
    // int x = 1000;
    // for (int i = 0; i < 4; i++)
    // {
    //     if ((num / x) % 10 == 6)
    //     {
    //         num = num + 3 * x;
    //         return num;
    //     }
    //     x = x / 10;
    // }
    // return num;
}
// @lc code=end
