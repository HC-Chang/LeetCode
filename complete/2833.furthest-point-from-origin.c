/*
 * @lc app=leetcode id=2833 lang=c
 *
 * [2833] Furthest Point From Origin
 */

// Difficulty:Easy

// You are given a string moves of length n consisting only of characters 'L', 'R', and '_'.
// The string represents your movement on a number line starting from the origin 0.

// In the ith move, you can choose one of the following directions:
// move to the left if moves[i] = 'L' or moves[i] = '_'
// move to the right if moves[i] = 'R' or moves[i] = '_'
// Return the distance from the origin of the furthest point you can get to after n moves.

// Constraints:

// 1 <= moves.length == n <= 50
// moves consists only of characters 'L', 'R' and '_'.

// @lc code=start
int furthestDistanceFromOrigin(char *moves)
{
    int l = 0;
    int r = 0;
    int m = 0;
    int len = strlen(moves);
    for (int i = 0; i < len; i++)
    {
        switch (moves[i])
        {
        case 'L':
            l++;
            break;
        case 'R':
            r++;
            break;
        case '_':
            m++;
            break;
        }
    }
    if (l == 0 && r == 0)
        return m;
    int max = fmax(l, r);
    int min = fmin(l, r);
    return max + m - min;
}
// @lc code=end