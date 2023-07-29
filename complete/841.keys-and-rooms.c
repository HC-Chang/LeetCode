/*
 * @lc app=leetcode id=841 lang=c
 *
 * [841] Keys and Rooms
 */

// @lc code=start
int count_arr_true(int *arr, int arr_size)
{
    int count = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == 1)
            count++;
    }
    return count;
}

void dfs(int cur, int *visited, int **rooms, int roomsSize, int *roomsColSize)
{
    visited[cur] = 1;
    for (int i = 0; i < roomsColSize[cur]; i++)
    {
        if (!visited[rooms[cur][i]] == 1)
            dfs(rooms[cur][i], visited, rooms, roomsSize, roomsColSize);
    }
}

bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize)
{
    int *visited = calloc(roomsSize, sizeof(int));
    dfs(0, visited, rooms, roomsSize, roomsColSize);
    bool b = count_arr_true(visited, roomsSize) == roomsSize;
    free(visited);
    return b;
}
// @lc code=end

// Note: DFS