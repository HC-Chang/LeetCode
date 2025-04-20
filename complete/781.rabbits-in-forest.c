/*
 * @lc app=leetcode id=781 lang=c
 *
 * [781] Rabbits in Forest
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int numRabbits(int *answers, int answersSize)
{
    if (answersSize == 0)
        return 0;

    int ans = 0;
    int max = 0;
    int j;
    int start;
    qsort(answers, answersSize, sizeof(int), sort);
    for (int i = 0; i < answersSize; i++)
    {
        ans += answers[i] + 1;
        max = answers[i] + 1;
        j = answers[i];
        start = i;
        while (i < answersSize && j == answers[i] && i - start < max)
            i++;
        i--;
    }
    return ans;
}
// @lc code=end

// Note: greedy