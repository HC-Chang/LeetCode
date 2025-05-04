/*
 * @lc app=leetcode id=1128 lang=c
 *
 * [1128] Number of Equivalent Domino Pairs
 */

// @lc code=start
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int arr[100] = {0};
    int ret = 0;
    int val;
    for (int i= 0; i< dominoesSize; i++)
    {
        val = dominoes[i][0] < dominoes[i][1] ? dominoes[i][0] * 10 + dominoes[i][1] : dominoes[i][1] * 10 + dominoes[i][0];
        ret += arr[val];
        arr[val]++;
    }
    return ret;
}
// @lc code=end

// Note: hash table