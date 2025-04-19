/*
 * @lc app=leetcode id=242 lang=c
 *
 * [242] Valid Anagram
 */

// @lc code=start
bool isAnagram(char *s, char *t)
{
    int s_len = strlen(s);
    if (s_len != strlen(t))
        return false;

    int map[26] = {0};
    for (int i = 0; i < s_len; i++)
    {
        map[s[i] - 'a']++;
        map[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if(map[i] != 0)
            return false;
    }
    return true;
}
// @lc code=end

// Solution 1: Sort String and Compare
// int sort(const void *a, const void *b) { return *(char *)a - *(char *)b; }

// bool isAnagram(char *s, char *t)
// {
//     int s_len = strlen(s);
//     int t_len = strlen(t);
//     if (s_len != t_len)
//         return false;
//     qsort(s, s_len, sizeof(char), sort);
//     qsort(t, t_len, sizeof(char), sort);
//     for (int i = 0; i < s_len; i++)
//     {
//         if (s[i] != t[i])
//             return false;
//     }
//     return true;
// }

// Note: hash table