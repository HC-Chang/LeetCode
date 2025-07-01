/*
 * @lc app=leetcode id=3330 lang=c
 *
 * [3330] Find the Original Typed String I
 */

// @lc code=start
int possibleStringCount(char *word)
{
    int n = strlen(word);
    int cnt = 1;
    for (int i = 1; i < n; ++i)
    {
        if (word[i - 1] == word[i])
            ++cnt;
    }
    return cnt;
}
// @lc code=end
