/*
 * @lc app=leetcode id=838 lang=c
 *
 * [838] Push Dominoes
 */

// @lc code=start
char *pushDominoes(char *dominoes)
{
    int n = strlen(dominoes);
    int f_arr[n];
    memset(f_arr, 0, sizeof(f_arr));

    int force = 0;
    for (int i = 0; i < n; i++)
    {
        if (dominoes[i] == 'R')
            force = n;
        else if (dominoes[i] == 'L')
            force = 0;
        else
            force = fmax(force - 1, 0);
        f_arr[i] += force;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (dominoes[i] == 'L')
            force = n;
        else if (dominoes[i] == 'R')
            force = 0;
        else
            force = fmax(force - 1, 0);
        f_arr[i] -= force;
    }
    for (int i = 0; i < n; i++)
    {
        if (f_arr[i] > 0)
            dominoes[i] = 'R';
        else if (f_arr[i] < 0)
            dominoes[i] = 'L';
        else
            dominoes[i] = '.';
    }

    return dominoes;
}
// @lc code=end

// Note: DP