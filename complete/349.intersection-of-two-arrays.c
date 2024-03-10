/*
 * @lc app=leetcode id=349 lang=c
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
        return false;

    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
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

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    HashItem *cnt = NULL;
    HashItem *find = NULL;
    for (int i = 0; i < nums1Size; i++)
        hashAddItem(&cnt, nums1[i], 1);

    *returnSize = 0;
    for (int i = 0; i < nums2Size; i++)
    {
        if (find = hashFindItem(&cnt, nums2[i]))
        {
            nums2[(*returnSize)++] = nums2[i];
            HASH_DEL(cnt, find);
        }
    }

    hashFree(&cnt);
    return nums2;
}
// @lc code=end

// Note: hash table