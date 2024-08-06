/*
 * @lc app=leetcode id=3016 lang=c
 *
 * [3016] Minimum Number of Pushes to Type Word II
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)b - *(int *)a; }
int minimumPushes(char *word)
{
    int hash[26] = {0};
    int n = strlen(word);
    for (int i = 0; i < n; i++)
        ++hash[word[i] - 'a'];

    qsort(&hash, 26, sizeof(int), sort);
    int sum_cnt = 0;
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] == 0)
            break;
        if (i % 8 == 0)
            cnt++;
        sum_cnt += hash[i] * cnt;
    }

    return sum_cnt;
}
// @lc code=end

// Note: hash table + sorting + counting