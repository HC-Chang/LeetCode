/*
 * @lc app=leetcode id=706 lang=c
 *
 * [706] Design HashMap
 */

// @lc code=start

typedef struct
{
    int arr[1000001];
} MyHashMap;

MyHashMap *myHashMapCreate()
{
    MyHashMap *obj = malloc(sizeof(MyHashMap));
    memset(obj, -1, (1e6 + 1) * sizeof(int));
    return obj;
}

void myHashMapPut(MyHashMap *obj, int key, int value)
{
    obj->arr[key] = value;
}

int myHashMapGet(MyHashMap *obj, int key)
{
    return obj->arr[key];
}

void myHashMapRemove(MyHashMap *obj, int key)
{
    obj->arr[key] = -1;
}

void myHashMapFree(MyHashMap *obj)
{
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/
// @lc code=end
