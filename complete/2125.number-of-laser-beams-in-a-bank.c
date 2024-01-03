/*
 * @lc app=leetcode id=2125 lang=c
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start
int numberOfBeams(char **bank, int bankSize)
{
    int size[bankSize];
    memset(size, 0, sizeof(size));
    int n;
    int cnt;
    for (int i = 0; i < bankSize; i++)
    {
        cnt = 0;
        n = strlen(bank[i]);
        for (int j = 0; j < n; j++)
        {
            if (bank[i][j] == '1')
                cnt++;
        }
        size[i] = cnt;
    }
    cnt = 0;
    int j;
    for (int i = 0; i < bankSize; i++)
    {
        while (i < bankSize - 1 && size[i] == 0)
            i++;
        j = i + 1;
        while (j < bankSize - 1 && size[j] == 0)
            j++;
        if (i >= bankSize || j >= bankSize)
            break;
        cnt += size[i] * size[j];
        i = j - 1;
    }
    return cnt;
}
// @lc code=end
