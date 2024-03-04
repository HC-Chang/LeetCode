/*
 * @lc app=leetcode id=948 lang=c
 *
 * [948] Bag of Tokens
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int bagOfTokensScore(int *tokens, int tokensSize, int power)
{
    if (tokensSize == 0)
        return 0;
    if (tokensSize == 1)
        return power > tokens[0];

    qsort(tokens, tokensSize, sizeof(int), sort);
    if (tokens[0] > power)
        return 0;

    int l = 0;
    int r = tokensSize - 1;
    int score = 0;
    while (l < r)
    {
        while (power >= tokens[l] && l < tokensSize)
        {
            power -= tokens[l++];
            score++;
        }

        if (score <= 0 || r - l <= 1)
            break;

        score--;
        power += tokens[r--];
        if (tokens[l] > power)
            break;
    }

    return score;
}
// @lc code=end

// Note: sorting + two pointers