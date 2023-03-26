/*
 * @lc app=leetcode id=2360 lang=c
 *
 * [2360] Longest Cycle in a Graph

 */

// @lc code=start
int longestCycle(int *edges, int edgesSize)
{
    int *visited = calloc(edgesSize, sizeof(int));
    int *path = malloc((edgesSize + 1) * sizeof(int));

    int max = -1;
    int index, node, dis_count;
    for (int i = 0; i < edgesSize; i++)
    {
        if (visited[i] == 1 || edges[i] == -1)
            continue;
        index = 0;

        path[index] = i;
        visited[i] = 1;
        node = edges[i];

        while (node != -1 && visited[node] != 1)
        {
            index++;
            path[index] = node;
            visited[node] = 1;
            node = edges[node];
        }
        if (node == -1)
            continue;
        if (visited[node] == 1)
        {
            dis_count = 0;
            while (index >= 0)
            {
                dis_count++;
                if (path[index] == node)
                    break;
                index--;
            }
            if (index >= 0)
            {
                if (dis_count > max)
                    max = dis_count;
            }
        }
    }
    free(path);
    free(visited);
    return max;
}

// @lc code=end
