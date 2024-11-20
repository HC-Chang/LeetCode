/*
 * @lc app=leetcode id=2516 lang=c
 *
 * [2516] Take K of Each Character From Left and Right
 */

// @lc code=start
int takeCharacters(char *s, int k)
{
    int count[3] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++)
        count[s[i] - 'a']++;

    for (int i = 0; i < 3; i++)
    {
        if (count[i] < k)
            return -1;
    }

    int window[3] = {0};
    int left = 0, maxWindow = 0;

    for (int right = 0; right < n; right++)
    {
        window[s[right] - 'a']++;

        while (left <= right && (count[0] - window[0] < k || count[1] - window[1] < k || count[2] - window[2] < k))
        {
            window[s[left] - 'a']--;
            left++;
        }

        maxWindow = fmax(maxWindow, right - left + 1);
    }

    return n - maxWindow;
}
// @lc code=end

// Note: hash table + sliding window

// Official Solution