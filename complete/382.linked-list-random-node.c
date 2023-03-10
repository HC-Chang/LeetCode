/*
 * @lc app=leetcode id=382 lang=c
 *
 * [382] Linked List Random Node
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct
{
    struct ListNode *head;

} Solution;

Solution *solutionCreate(struct ListNode *head)
{
    Solution *obj = calloc(1, sizeof(Solution));
    obj->head = head;
    return obj;
}

int solutionGetRandom(Solution *obj)
{
    int i = 1;
    int ans = 0;
    struct ListNode *ptr = obj->head;

    while (ptr)
    {
        if (rand() % i++ == 0)
            ans = ptr->val;
        ptr = ptr->next;
    }
    return ans;
}

void solutionFree(Solution *obj)
{
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);

 * solutionFree(obj);
*/
// @lc code=end
