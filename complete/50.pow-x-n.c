/*
 * @lc app=leetcode id=50 lang=c
 *
 * [50] Pow(x, n)
 */

// @lc code=start
double myPow(double x, int n)
{
    if (n == 0 || x == 1.0)
        return 1.0;
    else if (n == INT_MAX)
        return (x == 1) ? 1 : (x == -1) ? -1
                                        : 0;
    else if (n == INT_MIN)
        return (x == 1 || x == -1) ? 1 : 0;

    if (n < 0)
    {
        x = 1.0 / x;
        n = -n;
    }

    if (n % 2 == 0)
    {
        double half = myPow(x, n / 2);
        return half * half;
    }
    else
        return x * myPow(x, n - 1);
}
// @lc code=end

// Solution 1
// double myPow(double x, int n)
// {
//     if (n == INT_MAX)
//         return (x == 1) ? 1 : (x == -1) ? -1
//                                         : 0;
//     else if (n == INT_MIN)
//         return (x == 1 || x == -1) ? 1 : 0;
//     else if (!n || x == 1)
//         return 1;
//     else if (x == -1)
//         return -1;

//     double r = 1;
//     if (n > 0)
//     {
//         while (n > 0)
//         {
//             r *= x;
//             n--;
//         }
//     }
//     else if (n < 0)
//     {
//         n *= -1;
//         while (n > 0)
//         {
//             r *= x;
//             n--;
//         }
//         r = 1 / r;
//     }
//     return r;
// }