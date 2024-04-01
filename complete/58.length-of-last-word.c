/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start
// Solution 2:

int lengthOfLastWord(char* s) {
    if (!s)
        return 0;

    int cnt = 0;
    if (*s++ != ' ')
        cnt = 1;
    while(*s) {
        if (*s != ' ') {
            if(*(s-1) == ' ')
                cnt = 1;
            else
                cnt++;
        }
        s++;
    }
    return cnt;
}
// @lc code=end

// Solution 1: 

// int lengthOfLastWord(char *s)
// {
//     int count = 0;
//     int start = 0;
//     while (*s)
//     {
//         if (*s != ' ')
//         {
//             if (start == 0)
//             {
//                 start = 1;
//                 count = 1;
//             }
//             else
//                 count++;
//         }
//         else
//             start = 0;
//         s++;
//     }
//     return count;
// }