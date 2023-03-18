/*
 * @lc app=leetcode id=1472 lang=c
 *
 * [1472] Design Browser History
 */

// @lc code=start

typedef struct
{
    Node *prev;
    Node *next;
    char url[20];
} Node;

Node *new_node(char *url)
{
    Node *node = calloc(1, sizeof(Node));
    strcpy(node->url, url);
    return node;
}

typedef struct
{
    Node *curr;
} BrowserHistory;

BrowserHistory *browserHistoryCreate(char *homepage)
{
    BrowserHistory *obj = calloc(1, sizeof(BrowserHistory));
    obj->curr = new_node(homepage);
}

void browserHistoryVisit(BrowserHistory *obj, char *url)
{
    obj->curr->next = new_node(url);
    obj->curr->next->prev = obj->curr;
    obj->curr = obj->curr->next;
}

char *browserHistoryBack(BrowserHistory *obj, int steps)
{
    while (obj->curr->prev && steps-- > 0)
        obj->curr = obj->curr->prev;
    return obj->curr->url;
}

char *browserHistoryForward(BrowserHistory *obj, int steps)
{
    while (obj->curr->next && steps-- > 0)
        obj->curr = obj->curr->next;
    return obj->curr->url;
}

void browserHistoryFree(BrowserHistory *obj)
{
    while (obj->curr->prev)
        obj->curr = obj->curr->prev;
    NODE **free_node = calloc(1, sizeof(NODE *));
    while (obj->curr->next != NULL)
    {
        *free_node = obj->curr;
        obj->curr = obj->curr->next;
        free(*free_node);
    }
    free(free_node);
    free(obj->curr);
    free(obj);
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);

 * char * param_2 = browserHistoryBack(obj, steps);

 * char * param_3 = browserHistoryForward(obj, steps);

 * browserHistoryFree(obj);
*/
// @lc code=end
