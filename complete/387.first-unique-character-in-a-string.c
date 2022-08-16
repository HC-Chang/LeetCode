/*
 * @lc app=leetcode id=387 lang=c
 *
 * [387] First Unique Character in a String
 */

// @lc code=start

int firstUniqChar(char *s)
{
    char *start = s;
    int arr_count[26] = {0};
    int arr_index[26];
    for (int i = 0; i < 26; i++)
    {
        arr_index[i] = -1;
    }

    int cur_index = 0;
    while (*start)
    {
        if (arr_index[*start - 'a'] == -1)
        {
            ++arr_count[*start - 'a'];
            arr_index[*start - 'a'] = cur_index;
        }
        else if (arr_count[*start - 'a'] == 1)
        {
            arr_index[*start - 'a'] = -2;
        }

        cur_index++;
        start++;
    }

    int unique_index = cur_index;
    for (int i = 0; i < 26; i++)
    {
        if (arr_index[i] >= 0 && arr_index[i] < unique_index)
        {
            unique_index = arr_index[i];
        }
    }

    if (unique_index == cur_index)
    {
        return -1;
    }

    return unique_index;
}
// @lc code=end
// record count and index
// if count == 1
// then index = -2