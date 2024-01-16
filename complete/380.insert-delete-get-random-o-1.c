/*
 * @lc app=leetcode id=380 lang=c
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
typedef struct
{
    int val;
    int rec_idx;
    UT_hash_handle hh;
} Hash_Map;

typedef struct
{
    Hash_Map *map_main;
    int *record;
    int count;
} RandomizedSet;

RandomizedSet *randomizedSetCreate()
{

    RandomizedSet *random_set = malloc(sizeof(RandomizedSet));
    random_set->map_main = NULL;
    random_set->record = malloc(sizeof(int) * 6000);
    random_set->count = 0;
    return random_set;
}

bool randomizedSetInsert(RandomizedSet *obj, int val)
{

    Hash_Map *s;
    HASH_FIND_INT(obj->map_main, &val, s);

    if (!s)
    {
        Hash_Map *map = malloc(sizeof(Hash_Map));
        map->val = val;
        map->rec_idx = obj->count;
        HASH_ADD_INT(obj->map_main, val, map);
        obj->record[obj->count] = val;
        obj->count++;
        return true;
    }
    else
        return false;
}

bool randomizedSetRemove(RandomizedSet *obj, int val)
{

    Hash_Map *s;
    HASH_FIND_INT(obj->map_main, &val, s);

    if (s)
    {
        int top_val = obj->record[obj->count - 1];
        int rem_val_idx = s->rec_idx;

        obj->record[rem_val_idx] = top_val;
        HASH_DEL(obj->map_main, s);
        free(s);

        Hash_Map *s2;
        HASH_FIND_INT(obj->map_main, &top_val, s2);
        if (s2)
        {
            s2->rec_idx = rem_val_idx;
        }

        obj->count--;
        return true;
    }
    else
        return false;
}

int randomizedSetGetRandom(RandomizedSet *obj)
{
    int idx = rand() % (obj->count);
    return obj->record[idx];
}

void randomizedSetFree(RandomizedSet *obj)
{

    Hash_Map *s1, *s2;
    HASH_ITER(hh, obj->map_main, s1, s2)
    {
        HASH_DEL(obj->map_main, s1);
        free(s1);
    }
    free(obj->record);
    free(obj);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);

 * bool param_2 = randomizedSetRemove(obj, val);

 * int param_3 = randomizedSetGetRandom(obj);

 * randomizedSetFree(obj);
*/
// @lc code=end

// Note: hash table