/*
 * @lc app=leetcode id=633 lang=c
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
// Solution 2: math

bool judgeSquareSum(int c)
{
    int cnt;
    for (int i = 2; i * i <= c; i++)
    {
        if (c % i != 0)
            continue;
        cnt = 0;
        while (c % i == 0)
        {
            ++cnt;
            c /= i;
        }
        if (i % 4 == 3 && cnt % 2 != 0)
            return false;
    }
    return c % 4 != 3;
}
// @lc code=end

// Note: two pointers / math

// Solution 1: two pointers

// bool judgeSquareSum(int c) {
//     long l = 0;
//     long r = sqrt(c);
//     while (l <= r) {
//         if (l * l + r * r == c)
//             return true;
//         else if (l * l + r * r < c)
//             ++l;
//         else
//             --r;
//     }
//     return false;
// }