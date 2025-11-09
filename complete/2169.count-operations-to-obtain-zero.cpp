/*
 * @lc app=leetcode id=2169 lang=cpp
 *
 * [2169] Count Operations to Obtain Zero
 */

// @lc code=start
class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        if (!num1 || !num2)
            return 0;

        int big = max(num1, num2);
        int small = min(num1, num2);
        int cnt = 0;
        while (big && small)
        {
            cnt += big / small;
            big = big % small;
            swap(big, small);
        }

        return cnt;
    }
};
// @lc code=end

// Note: math + simulation

// Solution 1: reccursive

// class Solution
// {
// public:
//     int countOperations(int num1, int num2)
//     {
//         if (!num1 || !num2)
//             return 0;

//         if (num1 > num2)
//             return 1 + countOperations(num2, num1 - num2);
//         else
//             return 1 + countOperations(num2 - num1, num1);
//     }
// };