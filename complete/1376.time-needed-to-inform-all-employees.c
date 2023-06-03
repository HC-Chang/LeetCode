/*
 * @lc app=leetcode id=1376 lang=c
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
// Solution 2: DFS
int dfs(int i, int *manage, int *informTime)
{
    if (manage[i] != -1)
    {
        informTime[i] += dfs(manage[i], manage, informTime);
        manage[i] = -1;
    }
    return informTime[i];
}

int max(int a, int b) { return a > b ? a : b; }

int numOfMinutes(int n, int headID, int *manager, int managerSize, int *informTime, int informTimeSize)
{
    int r = 0;
    for (int i = 0; i < n; i++)
        r = max(r, dfs(i, manager, informTime));
    return r;
}
// @lc code=end

// Solution 1:

// int numOfMinutes(int n, int headID, int *manager, int managerSize, int *informTime, int informTimeSize)
// {
//     int max_time = 0;
//     int time;
//     int index;
//     int parent;
//     for (int i = 0; i < n; i++)
//     {
//         time = informTime[i];
//         index = i;
//         parent = manager[i];
//         while (parent != -1)
//         {
//             index = parent;
//             time += informTime[index];
//             parent = manager[parent];
//         }
//         if (time > max_time)
//             max_time = time;
//     }
//     return max_time;
// }