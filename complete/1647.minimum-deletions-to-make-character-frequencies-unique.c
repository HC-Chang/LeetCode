/*
 * @lc app=leetcode id=1647 lang=c
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)b - *(int *)a; }
int minDeletions(char *s)
{
    int hash[26] = {0};
    int s_len = strlen(s);
    for (int i = 0; i < s_len; i++)
        ++hash[s[i] - 'a'];

    qsort(&hash, 26, sizeof(int), sort);

    int flag[100000] = {0};
    int min_del = 0;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] == 0)
            break;

        if (flag[hash[i]] == 0)
            flag[hash[i]] = 1;
        else
        {
            while (1)
            {
                min_del++;
                hash[i]--;

                if (hash[i] == 0)
                    break;

                if (flag[hash[i]] == 0)
                {
                    flag[hash[i]] = 1;
                    break;
                }
            }
        }
    }

    return min_del;
}
// @lc code=end

// Note: hash table + greedy + sorting