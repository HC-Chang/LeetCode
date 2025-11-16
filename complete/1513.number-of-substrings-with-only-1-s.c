/*
 * @lc app=leetcode id=1513 lang=c
 *
 * [1513] Number of Substrings With Only 1s
 */

 // @lc code=start
int numSub(char* s) {
    const long long mod = 1e9 + 7;

    long long cnt = 0;
    long long tmp = 0;
    while (*s) {
        if (*s++ == '1')
            tmp++;
        else {
            cnt += ((1 + tmp) * (tmp) / 2) % mod;
            tmp = 0;
        }
    }

    cnt += ((1 + tmp) * (tmp) / 2) % mod;
    return cnt;
}
// @lc code=end

// Note: math