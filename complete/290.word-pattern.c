/*
 * @lc app=leetcode id=290 lang=c
 *
 * [290] Word Pattern
 */

// @lc code=start
unsigned long hash(unsigned char *str, int count)
{
    unsigned long hash = 5381;
    for (int i = 0; i < count; i++)
        hash = ((hash << 5) + hash) + str[i];

    return hash;
}

int add_hash(unsigned long *arrs, int index, unsigned long val)
{
    if (arrs[index] == 0)
    {
        arrs[index] = val;
        return 0;
    }
    else
    {
        if (arrs[index] == val)
            return 0;
        else
            return 1;
    }
}

int find_letter_end(int start, char *s)
{
    int len = strlen(s);
    for (int i = start; i < len; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
            return i - 1;
    }
    return len - 1;
}

bool wordPattern(char *pattern, char *s)
{
    unsigned long hash_arrs[26] = {0};
    int count = strlen(pattern);
    int s_len = strlen(s);
    int start_index = 0;
    int end_index = 0;
    for (int i = 0; i < count; i++)
    {
        end_index = find_letter_end(start_index, s);
        if (start_index > end_index)
            return false;
        if (add_hash(hash_arrs, pattern[i] - 'a', hash(s + start_index, end_index - start_index + 1)))
            return false;
        start_index = end_index + 2;
    }

    if (end_index != s_len - 1)
        return false;

    for (int i = 0; i < 26; i++)
    {
        if (hash_arrs[i] == 0)
            continue;
        for (int j = i + 1; j < 26; j++)
        {
            if (hash_arrs[i] == hash_arrs[j])
                return false;
        }
    }

    return true;
}
// @lc code=end
