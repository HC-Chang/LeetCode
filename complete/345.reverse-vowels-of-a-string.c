/*
 * @lc app=leetcode id=345 lang=c
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
bool is_vowels(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    else
        return false;
}
void swap(char *c1, char *c2)
{
    char c = *c1;
    *c1 = *c2;
    *c2 = c;
}
char *reverseVowels(char *s)
{
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right)
    {
        while (!is_vowels(s[left]) && left < right)
            left++;
        while (!is_vowels(s[right]) && left < right)
            right--;
        swap(s + left, s + right);

        left++;
        right--;
    }
    return s;
}
// @lc code=end
