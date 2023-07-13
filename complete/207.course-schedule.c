/*
 * @lc app=leetcode id=207 lang=c
 *
 * [207] Course Schedule
 */

// @lc code=start
typedef struct node
{
    int val;
    struct node *next;
} NODE;

#define NODE struct node

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize)
{
    int *indegree = (int *)calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++)
        indegree[prerequisites[i][0]]++;

    int *queue = (int *)calloc(numCourses, sizeof(int));
    int front = 0;
    int rear = 0;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    if (rear == front)
        return false;

    NODE **edgeList = (NODE **)calloc(numCourses, sizeof(NODE *));
    for (int i = 0; i < prerequisitesSize; i++)
    {
        int curVertex = prerequisites[i][1];
        int toVertex = prerequisites[i][0];
        NODE *newNode = (NODE *)malloc(sizeof(NODE));
        newNode->val = toVertex;
        if (edgeList[curVertex])
        {
            newNode->next = edgeList[curVertex];
            edgeList[curVertex] = newNode;
        }
        else
        {
            newNode->next = NULL;
            edgeList[curVertex] = newNode;
        }
    }

    int res_index = 0;
    int *res = (int *)malloc(sizeof(int) * numCourses);
    int zeroIndgree;
    while (front < rear)
    {
        zeroIndgree = queue[front++];
        res[res_index++] = zeroIndgree;
        for (NODE *cur = edgeList[zeroIndgree]; cur != NULL; cur = cur->next)
        {
            indegree[cur->val]--;
            if (indegree[cur->val] == 0)
                queue[rear++] = cur->val;
        }
    }

    for (int i = 0; i < numCourses; i++)
        free(edgeList[i]);

    free(edgeList);
    free(queue);
    free(indegree);
    free(res);

    if (res_index != numCourses)
        return false;

    return true;
}
// @lc code=end

// Note: topological sort