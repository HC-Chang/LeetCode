/*
 * @lc app=leetcode id=844 lang=c
 *
 * [844] Backspace String Compare
 */

// @lc code=start

char *m_str(char *s)
{
    int read = 0;
    int write = 0;
    while (s[read] != '\0')
    {
        if (s[read] != '#')
        {
            s[write] = s[read];
            write++;
        }
        else
        {
            // read++;
            if (write > 0)
            {
                write--;
            }
        }
        read++;
    }

    s[write] = '\0';
    
    return s;
}

// 雙指標
bool backspaceCompare(char *s, char *t)
{
    s = m_str(s);
    t = m_str(t);
    return strcmp(s, t) == 0;
}
// @lc code=end
