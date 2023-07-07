/*
 * @lc app=leetcode id=2024 lang=c
 *
 * [2024] Maximize the Confusion of an Exam
 */

// @lc code=start
int maxConsecutiveAnswers(char *answerKey, int k)
{
    int ans = 0;
    int maxCount = 0;
    int count[2] = {0};
    int len = strlen(answerKey);
    for (int l = 0, r = 0; r < len; ++r)
    {
        maxCount = fmax(maxCount, ++count[answerKey[r] == 'T']);
        while (maxCount + k < r - l + 1)
            --count[answerKey[l++] == 'T'];
        ans = fmax(ans, r - l + 1);
    }

    return ans;
}
// @lc code=end
