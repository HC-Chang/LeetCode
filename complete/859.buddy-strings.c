/*
 * @lc app=leetcode id=859 lang=c
 *
 * [859] Buddy Strings
 */

// @lc code=start
bool buddyStrings(char *s, char *goal)
{
    int len1 = strlen(s);
    int len2 = strlen(goal);
    if (len1 != len2)
        return false;
    if (!strcmp(s, goal) && len1 == 2 && s[0] != s[1])
        return false;
    int map1[26] = {0};
    int map2[26] = {0};
    int diff_count = 0;
    for (int i = 0; i < len1; i++)
    {
        ++map1[s[i] - 'a'];
        ++map2[goal[i] - 'a'];
        if (s[i] != goal[i])
            diff_count++;
    }
    int count_bigger2 = 0;
    for (int i = 0; i < 26; i++)
    {
        if (map1[i] != map2[i])
            return false;
        if (map1[i] >= 2)
            count_bigger2++;
    }
    if (diff_count == 2 || (diff_count == 0 && count_bigger2 >= 1))
        return true;

    return false;
}
// @lc code=end

// Note: Hash Table