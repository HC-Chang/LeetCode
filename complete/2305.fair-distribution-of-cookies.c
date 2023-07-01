/*
 * @lc app=leetcode id=2305 lang=c
 *
 * [2305] Fair Distribution of Cookies
 */

// @lc code=start
void dfs(int *min, int *haveAmount, int *cookies, int cookiesSize, int children, int nowMaximum, int nowAtCookie)
{
    if (nowAtCookie == cookiesSize)
    {
        if (*min > nowMaximum)
            *min = nowMaximum;
        return;
    }
    for (int i = 0; i < children; ++i)
    {
        haveAmount[i] += cookies[nowAtCookie];
        if (haveAmount[i] < min)
            dfs(min, haveAmount, cookies, cookiesSize, children, fmax(nowMaximum, haveAmount[i]), nowAtCookie + 1);
        haveAmount[i] -= cookies[nowAtCookie];
    }
}

int distributeCookies(int *cookies, int cookiesSize, int k)
{
    int min = INT_MAX;
    int haveAmount[8] = {0};
    dfs(&min, haveAmount, cookies, cookiesSize, k, 0, 0);
    return min;
}
// @lc code=end
