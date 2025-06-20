/*
 * @lc app=leetcode id=3443 lang=c
 *
 * [3443] Maximum Manhattan Distance After K Changes
 */

// @lc code=start
int maxDistance(char *s, int k)
{
    int pos[2] = {0};
    int cnt = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 'N':
            ++pos[0];
            break;
        case 'S':
            --pos[0];
            break;
        case 'E':
            ++pos[1];
            break;
        case 'W':
            --pos[1];
            break;
        }
        cnt = fmax(cnt, fmin(abs(pos[0]) + abs(pos[1]) + k * 2, i + 1));
    }
    return cnt;
}
// @lc code=end

// Note: hash table + math + counting

// Official Solution