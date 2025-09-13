/*
 * @lc app=leetcode id=3541 lang=c
 *
 * [3541] Find Most Frequent Vowel and Consonant
 */

// @lc code=start
int maxFreqSum(char *s)
{
    int hash[26];
    int max_v = 0;
    int max_c = 0;
    while (*s)
    {
        ++hash[*s - 'a'];
        switch (*s)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            if (hash[*s - 'a'] > max_v)
                max_v = hash[*s - 'a'];
            break;
        default:
            if (hash[*s - 'a'] > max_c)
                max_c = hash[*s - 'a'];
            break;
        }
        s++;
    }

    return max_v + max_c;
}
// @lc code=end

// Note: hash table + counting
