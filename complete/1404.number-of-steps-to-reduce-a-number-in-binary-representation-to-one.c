/*
 * @lc app=leetcode id=1404 lang=c
 *
 * [1404] Number of Steps to Reduce a Number in Binary Representation to One
 */

// @lc code=start
int numSteps(char *s)
{
    int n = strlen(s);
    int cnt = 0;
    bool meet_one = false;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '0')
            cnt += (meet_one ? 2 : 1);
        else
        {
            if (!meet_one)
            {
                if (i != 0)
                    cnt += 2;
                meet_one = true;
            }
            else
                cnt++;
        }
    }
    return cnt;
}
// @lc code=end

// Note: bit manipulation