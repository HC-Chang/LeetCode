/*
 * @lc app=leetcode id=705 lang=c
 *
 * [705] Design HashSet
 */

// @lc code=start
typedef struct
{
    int *arr;
} MyHashSet;

MyHashSet *myHashSetCreate()
{
    MyHashSet *obj = malloc(sizeof(MyHashSet));
    obj->arr = calloc(1e6 + 1, sizeof(int));
    return obj;
}

void myHashSetAdd(MyHashSet *obj, int key)
{
    ++obj->arr[key];
}

void myHashSetRemove(MyHashSet *obj, int key)
{
    obj->arr[key] = 0;
}

bool myHashSetContains(MyHashSet *obj, int key)
{
    return obj->arr[key] != 0;
}

void myHashSetFree(MyHashSet *obj)
{
    free(obj->arr);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/
// @lc code=end
