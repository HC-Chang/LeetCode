/*
 * @lc app=leetcode id=1716 lang=c
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
// Solution 2:

int totalMoney(int n)
{
    int q = n / 7;
    int r = n % 7;
    return (1 + 7) * 7 / 2 * q + (1 + q - 1) * (q - 1) / 2 * 7 + q * r + (1 + r) * r / 2;
}
// @lc code=end

// Solution 1:

// int totalMoney(int n)
// {
//     int sum = 1;
//     int idx = 2;
//     for (int i = 1; i < n; i++)
//     {
//         if (i % 7 == 0)
//             idx -= 6;
//         sum += idx++;
//     }

//     return sum;
// }
