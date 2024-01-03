/*
 * @lc app=leetcode id=2125 lang=c
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start
// Solution 2:
int numberOfBeams(char **bank, int bankSize)
{
    int n;
    int cnt = 0;
    int cur = 0;
    int pre = 0;
    for (int i = 0; i < bankSize; i++)
    {
        n = strlen(bank[i]);
        cur = 0;
        for (int j = 0; j < n; j++)
        {
            if (bank[i][j] == '1')
                cur++;
        }
        if (pre == 0)
            pre = cur;
        else if (cur != 0)
        {
            cnt += pre * cur;
            pre = cur;
        }
    }

    return cnt;
}
// @lc code=end

// Solution 1:
// int numberOfBeams(char **bank, int bankSize)
// {
//     int size[bankSize];
//     memset(size, 0, sizeof(size));
//     int n;
//     for (int i = 0; i < bankSize; i++)
//     {
//         n = strlen(bank[i]);
//         for (int j = 0; j < n; j++)
//         {
//             if (bank[i][j] == '1')
//                 size[i]++;
//         }
//     }
//     int cnt = 0;
//     int j;
//     for (int i = 0; i < bankSize; i++)
//     {
//         while (i < bankSize - 1 && size[i] == 0)
//             i++;
//         j = i + 1;
//         while (j < bankSize - 1 && size[j] == 0)
//             j++;
//         if (i >= bankSize || j >= bankSize)
//             break;
//         cnt += size[i] * size[j];
//         i = j - 1;
//     }
//     return cnt;
// }