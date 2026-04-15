/*
 * @lc app=leetcode id=2515 lang=c
 *
 * [2515] Shortest Distance to Target String in a Circular Array
 */

// @lc code=start
int closestTarget(char **words, int wordsSize, char *target, int startIndex)
{
    if (!strcmp(words[startIndex], target))
        return 0;
    int dis = INT_MAX;
    for (int i = 0; i < wordsSize; i++)
    {
        if (!strcmp(words[i], target))
        {
            int diff = abs(startIndex - i);
            dis = fmin(dis, fmin(diff, wordsSize - diff));
        }
    }

    if (dis == INT_MAX)
        return -1;
    return dis;
}
// @lc code=end
