/*
 * @lc app=leetcode id=560 lang=c
 *
 * [560] Subarray Sum Equals K
 */

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -10^7 <= k <= 10^7

// @lc code=start

// Solution: Hash Map

#define SIZE 20000

typedef struct hash
{
    int key;
    int val;
    struct hash *next;
} Hash;

Hash *init_hash()
{
    Hash *head = (Hash *)malloc(SIZE * sizeof(Hash));
    assert(head != NULL);
    memset(head, 0, sizeof(Hash) * SIZE);
    return head;
}

int get_hash(int key)
{
    return (key % SIZE + SIZE) % SIZE;
}

void add_hash(Hash *head, int key)
{
    // printf("1 key=%d head[key].key=%d head[key].val=%d\n", key, head[key].key, head[key].val);
    int pos = get_hash(key);
    if (head[pos].key == 0 && key != 0)
    {
        head[pos].key = key;
        head[pos].val = 1;
    }
    else if (head[pos].key == key)
        head[pos].val++;
    else
    {
        Hash *cur = &head[pos];
        while (cur->next != NULL && cur->key != key)
            cur = cur->next;
        if (cur->key == key)
            cur->val++;
        else
        {
            cur->next = (Hash *)malloc(sizeof(Hash));
            cur->next->key = key;
            cur->next->val = 1;
            cur->next->next = NULL;
        }
    }
    // printf("2 key=%d head[key].key=%d head[key].val=%d\n", key, head[key].key, head[key].val);
}
int hashFind(Hash *head, int key)
{
    // printf("1 key=%d head[key].key=%d head[key].val=%d\n", key, head[key].key, head[key].val);
    int pos = get_hash(key);
    // Hash node = head[pos];
    Hash *cur = &head[pos];
    while (cur != NULL && cur->key != key)
        cur = cur->next;
    if (cur == NULL)
        return 0;
    return cur->val;
}
void free_hash(Hash *head)
{
    for (int i = 0; i < SIZE; i++)
    {
        Hash *p = head[i].next;
        while (p != NULL)
        {
            Hash *tmp = p;
            p = p->next;
            free(tmp);
        }
    }
    free(head);
}

int subarraySum(int *nums, int numsSize, int k)
{
    Hash *head = init_hash();
    add_hash(head, 0);
    int preSum = 0, ans = 0;
    for (int i = 0; i < numsSize; i++)
    {
        preSum += nums[i];
        // int val = GetHash(preSum - k);
        ans += hashFind(head, preSum - k);
        // printf("i=%d nums[i]=%d preSum=%d val=%d ans=%d\n", i, nums[i], preSum, val, ans);
        // val = GetHash(preSum);
        add_hash(head, preSum);
    }
    free_hash(head);
    return ans;
}
// @lc code=end

// #define CAPACITY 10000000
// int subarraySum(int *nums, int numsSize, int k)
// {
//     // Hash Table -> Avoid Time Limit Exceeded
//     // -10^7 <= k <= 10^7
//     int *hash_table = calloc(CAPACITY * 2 + 1, sizeof(int));
//     int sum = 0;
//     int count = 0;
//     hash_table[CAPACITY] = 1;
//     for (int i = 0; i < numsSize; i++)
//     {
//         sum += nums[i];
//         count += hash_table[sum - k + CAPACITY];
//         ++hash_table[sum + CAPACITY];
//     }
//     return count;
// }