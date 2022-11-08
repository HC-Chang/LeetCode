/*
 * @lc app=leetcode id=205 lang=c
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
bool isIsomorphic(char *s, char *t)
{
    int map1[128] = {0};
    int map2[128] = {0};
    for (int i = 0; i < strlen(s); ++i)
    {
        if (map1[s[i]] != map2[t[i]])
            return false;
        map1[s[i]] = i + 1;
        map2[t[i]] = i + 1;
    }
    return true;
}
// @lc code=end
// map size = 128 (ASCII Code)