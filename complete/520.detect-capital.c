/*
 * @lc app=leetcode id=520 lang=c
 *
 * [520] Detect Capital
 */

// @lc code=start
bool detectCapitalUse(char *word)
{
    if (strlen(word) < 2)
        return true;
    if (*word >= 97)
    {
        word++;
        while (*word)
        {
            if (*word++ < 97)
                return false;
        }
    }
    else
    {
        word++;
        if (*word >= 97)
        {
            word++;
            while (*word)
            {
                if (*word++ < 97)
                    return false;
            }
        }
        else
        {
            word++;
            while (*word)
            {
                if (*word++ >= 97)
                    return false;
            }
        }
    }
    return true;
}
// @lc code=end

// bool all_upper_or_lower(bool is_upper, char *word)
// {
//     if (is_upper)
//     {
//         while (*word)
//         {
//             if (*word++ >= 97)
//                 return false;
//         }
//     }
//     else
//     {
//         while (*word)
//         {
//             if (*word++ < 97)
//                 return false;
//         }
//     }
//     return true;
// }

// bool detectCapitalUse(char *word)
// {
//     if (strlen(word) < 2)
//         return true;
//     if (*word++ >= 97)
//     {
//         if (all_upper_or_lower(false, word) == false)
//             return false;
//     }
//     else
//     {
//         if (*word++ >= 97)
//         {
//             if (all_upper_or_lower(false, word) == false)
//                 return false;
//         }
//         else
//         {
//             if (all_upper_or_lower(true, word) == false)
//                 return false;
//         }
//     }
//     return true;
// }