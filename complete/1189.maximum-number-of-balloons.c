/*
 * @lc app=leetcode id=1189 lang=c
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
int maxNumberOfBalloons(char *text)
{
    int n = strlen(text);
    int hash[26] = {0};
    for (int i = 0; i < n; i++)
        hash[text[i] - 'a']++;

    return fmin(fmin(fmin(hash['b' - 'a'], hash['a' - 'a']), hash['l' - 'a'] / 2), fmin(hash['o' - 'a'] / 2, hash['n' - 'a']));
}
// @lc code=end
