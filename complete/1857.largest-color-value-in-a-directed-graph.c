/*
 * @lc app=leetcode id=1857 lang=c
 *
 * [1857] Largest Color Value in a Directed Graph
 */

// @lc code=start
int MAX(int a, int b) { return a > b ? a : b; }
int largestPathValue(char *colors, int **edges, int edgesSize, int *edgesColSize)
{
    int n = strlen(colors);

    int **in = malloc(sizeof(int *) * n);
    int *len_in = calloc(n, sizeof(int));
    int *index_in = calloc(n, sizeof(int));

    int **out = malloc(sizeof(int *) * n);
    int *len_out = calloc(n, sizeof(int));
    int *index_out = calloc(n, sizeof(int));

    int *group = malloc(sizeof(int) * n);
    int **count_arr = malloc(n * sizeof(int *));
    int max_count = -1;

    for (int i = 0; i < edgesSize; i++)
    {
        if (edges[i][0] == edges[i][1])
            return -1;

        len_out[edges[i][0]]++;
        len_in[edges[i][1]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (len_in[i] > 0)
            in[i] = malloc(sizeof(int) * len_in[i]);

        if (len_out[i] > 0)
            out[i] = malloc(sizeof(int) * len_out[i]);

        count_arr[i] = calloc(26, sizeof(int));
    }

    for (int i = 0; i < edgesSize; i++)
        out[edges[i][0]][index_out[edges[i][0]]++] = edges[i][1];

    int start_index = 0;
    int end_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (len_in[i] == 0)
            group[end_index++] = i;
    }

    int current, temp;
    int current_number;
    int next_number;
    while (start_index < end_index)
    {
        current = group[start_index];
        count_arr[current][colors[current] - 'a']++;
        for (int i = 0; i < len_out[current]; i++)
        {
            temp = out[current][i];
            len_in[temp]--;
            if (len_in[temp] == 0)
                group[end_index++] = temp;

            for (int j = 0; j < 26; j++)
            {
                current_number = count_arr[current][j];
                next_number = count_arr[temp][j];
                count_arr[temp][j] = MAX(current_number, next_number);
            }
        }
        start_index++;
    }

    if (end_index < n)
        return -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
            max_count = MAX(max_count, count_arr[i][j]);
    }

    return max_count;
}
// @lc code=end

// Note: Topological Sort + DP