/*
 * @lc app=leetcode id=1399 lang=c
 *
 * [1399] Count Largest Group
 */

// @lc code=start
#define HASH_SIZE 37

int countLargestGroup(int n)
{
    int hash[HASH_SIZE] = {0};
    int max_val = 0;
    int tmp;
    int tmp_sum;
    for (int i = 1; i <= n; i++)
    {
        tmp = i;
        tmp_sum = 0;
        while (tmp)
        {
            tmp_sum += tmp % 10;
            tmp /= 10;
        }
        ++hash[tmp_sum];
        max_val = fmax(max_val, hash[tmp_sum]);
    }

    int cnt = 0;
    for (int i = 0; i < HASH_SIZE; i++)
    {
        if (hash[i] == max_val)
            cnt++;
    }
    return cnt;
}
// @lc code=end

// Note: hash table
