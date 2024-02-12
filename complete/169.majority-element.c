/*
 * @lc app=leetcode id=169 lang=c
 *
 * [169] Majority Element
 */

// @lc code=start
typedef struct
{
    int cnt;
    int idx;
    UT_hash_handle hh;
} HASH;

HASH *hash = NULL;

void add_hash(int idx, int *max_val, int *max_cnt, bool *over_half, int total_cnt)
{
    HASH *tmp;
    HASH_FIND_INT(hash, &idx, tmp);
    if (tmp == NULL)
    {
        tmp = malloc(sizeof(HASH));
        tmp->idx = idx;
        tmp->cnt = 1;
        HASH_ADD_INT(hash, idx, tmp);
    }
    else
    {
        if (++tmp->cnt > *max_cnt)
        {
            *max_cnt = tmp->cnt;
            *max_val = idx;
            if (*max_cnt > (total_cnt / 2 + 1))
                *over_half = true;
        }
    }
}

void free_hash()
{
    HASH *cur, *tmp;
    HASH_ITER(hh, hash, cur, tmp)
    {
        HASH_DEL(hash, cur);
        free(cur);
    }
}

int majorityElement(int *nums, int numsSize)
{
    int max_val = nums[0];
    int max_cnt = 1;
    bool over_half = false;
    for (int i = 0; i < numsSize; i++)
    {
        add_hash(nums[i], &max_val, &max_cnt, &over_half, numsSize);
        if (over_half)
            break;
    }

    free_hash();
    return max_val;
}
// @lc code=end

// Note: hash table