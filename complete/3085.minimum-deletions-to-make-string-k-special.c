/*
 * @lc app=leetcode id=3085 lang=c
 *
 * [3085] Minimum Deletions to Make String K-Special
 */

// @lc code=start
int minimumDeletions(char *word, int k)
{
    int cnt[26] = {0};
    int n = strlen(word);
    for (int i = 0; i < n; i++)
        cnt[word[i] - 'a']++;

    int res = n;
    for (int i = 0; i < 26; i++)
    {
        int deleted = 0;
        for (int j = 0; j < 26; j++)
        {
            if (cnt[i] > cnt[j])
                deleted += cnt[j];
            else if (cnt[j] > cnt[i] + k)
                deleted += cnt[j] - (cnt[i] + k);
        }
        res = fmin(res, deleted);
    }
    return res;
}
// @lc code=end

// Note: hash table + + sorting + greedy