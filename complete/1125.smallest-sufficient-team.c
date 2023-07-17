/*
 * @lc app=leetcode id=1125 lang=c
 *
 * [1125] Smallest Sufficient Team
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
    {
        return false;
    }
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
    {
        hashAddItem(obj, key, val);
    }
    else
    {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem **obj, char *key, int defaultVal)
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

int *smallestSufficientTeam(char **req_skills, int req_skillsSize, char ***people, int peopleSize, int *peopleColSize, int *returnSize)
{
    HashItem *skill_index = NULL;
    for (int i = 0; i < req_skillsSize; ++i)
        hashAddItem(&skill_index, req_skills[i], i);

    int dp[1 << req_skillsSize];
    int prev_skill[1 << req_skillsSize], prev_people[1 << req_skillsSize];
    memset(prev_skill, 0, sizeof(prev_skill));
    memset(prev_people, 0, sizeof(prev_people));
    dp[0] = 0;
    for (int i = 1; i < (1 << req_skillsSize); i++)
        dp[i] = peopleSize;

    for (int i = 0; i < peopleSize; ++i)
    {
        int cur_skill = 0;
        for (int j = 0; j < peopleColSize[i]; j++)
            cur_skill |= 1 << hashGetItem(&skill_index, people[i][j], 0);

        for (int prev = 0; prev < (1 << req_skillsSize); prev++)
        {
            int comb = prev | cur_skill;
            if (dp[comb] > dp[prev] + 1)
            {
                dp[comb] = dp[prev] + 1;
                prev_skill[comb] = prev;
                prev_people[comb] = i;
            }
        }
    }

    hashFree(&skill_index);
    int *res = (int *)calloc(peopleSize, sizeof(int));
    int i = (1 << req_skillsSize) - 1;
    int pos = 0;
    while (i > 0)
    {
        res[pos++] = prev_people[i];
        i = prev_skill[i];
    }
    *returnSize = pos;
    return res;
}

// @lc code=end

// Official Solution
// Note: hashmap + DP + bit manipulation
