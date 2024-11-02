/*
 * @lc app=leetcode id=2490 lang=c
 *
 * [2490] Circular Sentence
 */

// @lc code=start
bool isCircularSentence(char *sentence)
{
    int n = strlen(sentence);
    for (int i = 0; i < n; i++)
    {
        if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
            return false;
    }
    return sentence[0] == sentence[n - 1] ? true : false;
}
// @lc code=end
