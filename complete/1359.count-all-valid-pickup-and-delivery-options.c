/*
 * @lc app=leetcode id=1359 lang=c
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
// Solution 2: DP
int countOrders(int n)
{
    int mod = 1e9 + 7;
    long long ret = 1;
    for (int i = 2; i <= n; i++)
        ret = ret * i * (2 * i - 1) % mod;
    return ret;
}
// @lc code=end

// Note: DP

// Solution 1: 模倒數 modular multiplicative inverse

// (2n)! / (2^n)
// inv[2] = 5e8 + 4

// int countOrders(int n){
//     int mod = 1e9+7;
//     long long ret = 1;
//     for (int i = 1; i<=n; i++){
//         ret *= (2*i)*(2*i-1);
//         ret %= mod;
//         ret *= 500000004;
//         ret %= mod;
//     }
//     return ret;
// }

// ref: https://yuihuang.com/lc-1359/