/*
 * @lc app=leetcode id=1743 lang=c
 *
 * [1743] Restore the Array From Adjacent Pairs
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct HashTable
{
    int key;
    int arr[2];
    UT_hash_handle hh;
};

void push(struct HashTable **hashTable, int x, int y)
{
    struct HashTable *tmp;
    HASH_FIND_INT(*hashTable, &x, tmp);
    if (tmp == NULL)
    {
        tmp = (struct HashTable *)malloc(sizeof(struct HashTable));
        tmp->key = x, tmp->arr[0] = y, tmp->arr[1] = INT_MAX;
        HASH_ADD_INT(*hashTable, key, tmp);
    }
    else
        tmp->arr[1] = y;
}

struct HashTable *query(struct HashTable **hashTable, int x)
{
    struct HashTable *tmp;
    HASH_FIND_INT(*hashTable, &x, tmp);
    return tmp;
}

int *restoreArray(int **adjacentPairs, int adjacentPairsSize, int *adjacentPairsColSize, int *returnSize)
{
    struct HashTable *hashTable = NULL;
    for (int i = 0; i < adjacentPairsSize; i++)
    {
        push(&hashTable, adjacentPairs[i][0], adjacentPairs[i][1]);
        push(&hashTable, adjacentPairs[i][1], adjacentPairs[i][0]);
    }

    int n = adjacentPairsSize + 1;
    int *ret = (int *)malloc(sizeof(int) * n);
    *returnSize = n;
    struct HashTable *iter, *tmp;
    HASH_ITER(hh, hashTable, iter, tmp)
    {
        if (iter->arr[1] == INT_MAX)
            ret[0] = iter->key;
    }
    ret[1] = query(&hashTable, ret[0])->arr[0];
    for (int i = 2; i < n; i++)
    {
        int *adj = query(&hashTable, ret[i - 1])->arr;
        ret[i] = ret[i - 2] == adj[0] ? adj[1] : adj[0];
    }
    return ret;
}
// @lc code=end

// Official Solution

// Note: hash table
