/*
 * @lc app=leetcode id=2582 lang=cpp
 *
 * [2582] Pass the Pillow
 */

// Difficulty:Easy

// There are n people standing in a line labeled from 1 to n.
// The first person in the line is holding a pillow initially.
// Every second, the person holding the pillow passes it to the next person standing in the line.
// Once the pillow reaches the end of the line, the direction changes,
// and people continue passing the pillow in the opposite direction.

// For example, once the pillow reaches the nth person they pass it to the n - 1th person,
//  then to the n - 2th person and so on.
// Given the two positive integers n and time,
// return the index of the person holding the pillow after time seconds.

// Constraints:
// 2 <= n <= 1000
// 1 <= time <= 1000

// @lc code=start
class Solution
{
public:
    int passThePillow(int n, int time)
    {
        if (time + 1 <= n)
            return time + 1;

        int r = (time + 1) % (n * 2 - 2);
        if (r > n)
            r = n - (r - n);
        if (r == 0)
            r = 2;
        return r;
    }
};
// @lc code=end

// Note: simulation