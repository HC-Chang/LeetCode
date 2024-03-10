// uthash (<char*, int>/<int, int>)
// Similar Questions: 349.1048

// uthash: <char*, int>
typedef struct
{
    char *key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, char *key)
{
    HashItem *pEntry = NULL;
    HASH_FIND_STR(*obj, key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, char *key, int val)
{
    if (hashFindItem(obj, key))
        return false;

    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem **obj, char *key, int val)
{
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry)
        hashAddItem(obj, key, val);
    else
        pEntry->val = val;
    return true;
}

int hashGetItem(HashItem **obj, char *key, int defaultVal)
{
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry)
        return defaultVal;

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

// uthash: <int, int>
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

bool hashSetItem(HashItem **obj, int key, int val)
{
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry)
        hashAddItem(obj, key, val);
    else
        pEntry->val = val;
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal)
{
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry)
        return defaultVal;

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