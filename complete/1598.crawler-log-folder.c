/*
 * @lc app=leetcode id=1598 lang=c
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
int minOperations(char **logs, int logsSize)
{
    int cnt = 0;
    for (int i = 0; i < logsSize; i++)
    {
        if (!strcmp("../", logs[i]))
        {
            if (cnt > 0)
                cnt--;
        }
        else if (!strcmp("./", logs[i]))
            continue;
        else
            cnt++;
    }
    return cnt;
}
// @lc code=end
