/*
 * @lc app=leetcode id=1657 lang=c
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)b - *(int *)a; }
bool closeStrings(char *word1, char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    if (len1 != len2)
        return false;
    int map1[26] = {0};
    int map2[26] = {0};
    for (int i = 0; i < len1; i++)
    {
        ++map1[word1[i] - 'a'];
        ++map2[word2[i] - 'a'];
    }
    for (int i = 0; i < 26; i++)
    {
        if ((map1[i] == 0 && map2[i] != 0) || (map1[i] != 0 && map2[i] == 0))
            return false;
    }
    qsort(&map1, 26, sizeof(int), sort);
    qsort(&map2, 26, sizeof(int), sort);
    for (int i = 0; i < 26; i++)
    {
        if (map1[i] != map2[i])
            return false;
        if (map1[i] == 0)
            break;
    }
    return true;
}
// @lc code=end
