/*
 * @lc app=leetcode id=299 lang=c
 *
 * [299] Bulls and Cows
 */

// @lc code=start
int min(int a, int b) { return a < b ? a : b; }
char *getHint(char *secret, char *guess)
{
    int count_a = 0;
    int count_b = 0;
    int arr_secret[10] = {0};
    int arr_guess[10] = {0};
    while (*secret)
    {
        if (*secret == *guess)
            ++count_a;
        else
        {
            ++arr_secret[*secret - '0'];
            ++arr_guess[*guess - '0'];
        }
        ++secret;
        ++guess;
    }
    for (int i = 0; i < 10; i++)
    {
        if (arr_secret[i] != 0)
            count_b += min(arr_secret[i], arr_guess[i]);
    }
    char *ans = malloc(10 * sizeof(char));
    sprintf(ans, "%iA%iB", count_a, count_b);

    return ans;
}
// @lc code=end
