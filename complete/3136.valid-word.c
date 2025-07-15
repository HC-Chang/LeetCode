/*
 * @lc app=leetcode id=3136 lang=c
 *
 * [3136] Valid Word
 */

// @lc code=start
bool isValid(char *word)
{
    int n = strlen(word);
    if (n < 3)
        return false;
    bool has_vow = false;
    bool has_con = false;
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(word[i]) && !isdigit(word[i]))
            return false;
        if (isdigit(word[i]))
            continue;
        switch (word[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            has_vow = true;
            break;
        default:
            has_con = true;
            break;
        }
    }

    return has_vow && has_con;
}
// @lc code=end
