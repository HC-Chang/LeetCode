/*
 * @lc app=leetcode id=1814 lang=c
 *
 * [1814] Count Nice Pairs in an Array
 */

// @lc code=start
typedef struct
{
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key)
{
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val)
{
    if (hashFindItem(obj, key))
    {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem **obj, int key, int val)
{
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry)
    {
        hashAddItem(obj, key, val);
    }
    else
    {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal)
{
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry)
    {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem **obj)
{
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp)
    {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int countNicePairs(int *nums, int numsSize)
{
    const int MOD = 1000000007;
    int res = 0;
    HashItem *h = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        int temp = nums[i], j = 0;
        while (temp > 0)
        {
            j = j * 10 + temp % 10;
            temp /= 10;
        }
        int val = hashGetItem(&h, nums[i] - j, 0);
        res = (res + val) % MOD;
        hashSetItem(&h, nums[i] - j, val + 1);
    }
    hashFree(&h);
    return res;
}
// @lc code=end

// Official Solution

// Note: hash table