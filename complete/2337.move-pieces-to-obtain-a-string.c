/*
 * @lc app=leetcode id=2337 lang=c
 *
 * [2337] Move Pieces to Obtain a String
 */

// @lc code=start
bool canChange(char *start, char *target)
{
    int n = strlen(start);
    int s_idx = 0;
    int t_idx = 0;
    while (s_idx < n || t_idx < n)
    {
        while (s_idx < n && start[s_idx] == '_')
            s_idx++;
        while (t_idx < n && target[t_idx] == '_')
            t_idx++;
        if (start[s_idx] != target[t_idx] || (start[s_idx] == 'L' && s_idx < t_idx) || (start[s_idx] == 'R' && s_idx > t_idx))
            return false;

        s_idx++;
        t_idx++;
    }

    return true;
}
// @lc code=end

// Note: two pointers