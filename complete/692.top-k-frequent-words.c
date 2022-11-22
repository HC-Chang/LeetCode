/*
 * @lc app=leetcode id=692 lang=c
 *
 * [692] Top K Frequent Words
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int frequence;
    int length;
    char *str;
} DATA;

typedef struct
{
    int idx;
    int length;
    char *str;
} hashInfo;

typedef struct
{
    int size;
    int mod;
    hashInfo **arr;
} HASH;

int hash(HASH *obj, char *str, int keyLen)
{
    size_t hash = 5381;
    while (*str)
    {
        hash = 33 * hash ^ (unsigned char)*str++;
    }
    return hash % obj->size;
}

HASH *create_hash(int size)
{
    HASH *obj = malloc(sizeof(HASH));
    obj->size = size;
    obj->mod = size;
    obj->arr = malloc(sizeof(hashInfo) * (size));
    for (int x = 0; x < size; x++)
    {
        hashInfo *newInfo = calloc(1, sizeof(hashInfo));
        newInfo->idx = -1;
        obj->arr[x] = newInfo;
    }
    return obj;
}

void add_hash(HASH *ht, char *key, int idx)
{
    int keyLen = strlen(key);
    int index = hash(ht, key, keyLen);
    while (ht->arr[index]->idx != -1)
    {
        index++;
        index %= ht->size;
    }

    ht->arr[index]->str = calloc(keyLen + 1, sizeof(char));
    ht->arr[index]->idx = idx;
    ht->arr[index]->length = keyLen;
    strncpy(ht->arr[index]->str, key, keyLen);
}

int find_hash(HASH *ht, char *key)
{
    int keyLen = strlen(key);
    int index = hash(ht, key, keyLen);
    while (ht->arr[index]->idx != -1)
    {
        if (keyLen == ht->arr[index]->length &&
            !strcmp(ht->arr[index]->str, key))
        {
            return ht->arr[index]->idx;
        }
        index++;
        index %= ht->size;
    }
    return -1;
}

void free_hash(HASH *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        free(ht->arr[i]->str);
        free(ht->arr[i]);
    }
    free(ht->arr);
    free(ht);
}

int compare(const void *a, const void *b)
{
    DATA *n1 = (DATA *)a;
    DATA *n2 = (DATA *)b;

    if (n1->frequence == n2->frequence)
    {
        int idx1 = 0;
        int idx2 = 0;
        return strcmp(n2->str, n1->str);
    }
    return n1->frequence - n2->frequence;
}

char **topKFrequent(char **words, int wordsSize, int k, int *returnSize)
{
    HASH *h = create_hash(wordsSize);
    DATA *tmp = malloc(sizeof(DATA) * wordsSize);
    int tmpCtr = 0;
    for (int i = 0; i < wordsSize; i++)
    {
        int findIdx = find_hash(h, words[i]);
        if (-1 == findIdx)
        {
            add_hash(h, words[i], tmpCtr);
            int tmpLen = strlen(words[i]);
            tmp[tmpCtr].frequence = 1;
            tmp[tmpCtr].length = tmpLen;
            tmp[tmpCtr].str = calloc(tmpLen + 1, sizeof(char));
            memcpy(tmp[tmpCtr].str, words[i], sizeof(char) * tmpLen);
            tmpCtr++;
        }
        else
        {
            tmp[findIdx].frequence += 1;
        }
    }

    qsort(tmp, tmpCtr, sizeof(DATA), compare);

    char **r = malloc(sizeof(char *) * k);
    int retCtr = 0;
    for (int x = 0; x < k; x++)
    {
        r[retCtr] = calloc(tmp[tmpCtr - 1].length + 1, sizeof(char));
        memcpy(r[retCtr], tmp[tmpCtr - 1].str, sizeof(char) * (tmp[tmpCtr - 1].length));
        free(tmp[tmpCtr - 1].str);
        retCtr++;
        tmpCtr--;
    }

    for (int x = 0; x < tmpCtr; x++)
    {
        free(tmp[x].str);
    }
    free(tmp);
    free_hash(h);

    *returnSize = k;
    return r;
}

// @lc code=end

// Hash 紀錄出現頻率
// 依頻率與字母大小取前 k 個
// Ref: https://hackmd.io/@kenjin/rJdUR4iGS