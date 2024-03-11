/*
 * @lc app=leetcode id=791 lang=c
 *
 * [791] Custom Sort String
 */

// @lc code=start
char *customSortString(char *order, char *s)
{
    int hash[26] = {0};
    int l1 = strlen(order);
    int l2 = strlen(s);

    for (int i = 0; i < l2; i++)
        ++hash[s[i] - 'a'];

    char *ans = malloc((l2 + 1) * sizeof(char));
    int idx = 0;
    for (int i = 0; i < l1; i++)
    {
        while (hash[order[i] - 'a']-- > 0)
            ans[idx++] = order[i];
    }

    for (int i = 0; i < l2; i++)
    {
        if (hash[s[i] - 'a'] > 0)
            ans[idx++] = s[i];
    }
    ans[l2] = '\0';
    return ans;
}
// @lc code=end

// Note: hash table