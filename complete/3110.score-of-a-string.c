/*
 * @lc app=leetcode id=3110 lang=c
 *
 * [3110] Score of a String
 */

// @lc code=start
int scoreOfString(char *s)
{
    int n = strlen(s);
    int score = 0;
    for (int i = 1; i < n; i++)
        score += abs(s[i] - s[i - 1]);
    return score;
}
// @lc code=end
