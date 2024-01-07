/*
 * @lc app=leetcode id=446 lang=c
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
struct sequence_hash
{
    long long diff;
    int count;
    UT_hash_handle hh;
};

int numberOfArithmeticSlices(int *nums, int numsSize)
{
    int ret = 0;
    struct sequence_hash **dp = calloc(numsSize, sizeof(struct sequence_hash *));
    long long  diff;
    for (int end = 1; end < numsSize; ++end)
    {
        for (int i = 0; i < end; ++i)
        {
            diff = ((long long)nums[end]) - nums[i];
            struct sequence_hash *end_entry;
            HASH_FIND(hh, dp[end], &diff, sizeof(diff), end_entry);
            if (!end_entry)
            { 
                end_entry = malloc(sizeof(struct sequence_hash));
                end_entry->diff = diff;
                end_entry->count = 0;
                HASH_ADD(hh, dp[end], diff, sizeof(end_entry->diff), end_entry);
            }

            struct sequence_hash *prev_entry;
            HASH_FIND(hh, dp[i], &diff, sizeof(diff), prev_entry);
            if (!prev_entry)
                ++end_entry->count;
            else
            {
                end_entry->count += prev_entry->count + 1;
                ret += prev_entry->count;
            }
        }
    }

    for (int i = 0; i < numsSize; ++i)
    {
        struct sequence_hash *entry;
        struct sequence_hash *tmp;
        HASH_ITER(hh, dp[i], entry, tmp)
        {
            HASH_DEL(dp[i], entry);
            free(entry);
        }
    }
    free(dp);

    return ret;
}
// @lc code=end

// Note: hash map + DP