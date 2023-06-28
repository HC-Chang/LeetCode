/*
 * @lc app=leetcode id=1514 lang=c
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
typedef struct
{
    int x;
    int y;
} QUEUE;

double prob[10001][10001];
int matrix[10001][10001];
QUEUE q[100000];
double memo[10001];

double maxProbability(int n, int **edges, int edgesSize, int *edgesColSize, double *succProb, int succProbSize, int start, int end)
{
    for (int i = 0; i < n; i++)
    {
        matrix[i][10000] = 0;
        memo[i] = 0;
    }
    memo[start] = 1;

    int row;
    int nextPos;
    int len;
    for (int i = 0; i < edgesSize; i++)
    {
        row = edges[i][0];
        nextPos = edges[i][1];
        len = matrix[row][10000];
        matrix[row][len] = nextPos;
        prob[row][nextPos] = succProb[i];
        len++;
        matrix[row][10000] = len;

        row = edges[i][1];
        nextPos = edges[i][0];
        len = matrix[row][10000];
        matrix[row][len] = nextPos;
        prob[row][nextPos] = succProb[i];
        len++;
        matrix[row][10000] = len;
    }
    int tail = 0;
    int head = 0;
    int x;
    int y;
    double t_prob;
    for (int i = 0; i < matrix[start][10000]; i++)
    {
        x = start;
        y = matrix[start][i];
        t_prob = prob[x][y];
        q[tail].x = x;
        q[tail].y = y;
        memo[y] = t_prob;
        tail++;
    }
    while (head < tail)
    {
        int row = q[head].y;
        double curProb = memo[row];
        for (int i = 0; i < matrix[row][10000]; i++)
        {
            x = row;
            y = matrix[x][i];
            t_prob = prob[x][y];
            if (t_prob * curProb > memo[y])
            {
                q[tail].x = x;
                q[tail].y = y;
                memo[y] = t_prob * curProb;
                tail++;
            }
        }
        head++;
    }

    return memo[end];
}
// @lc code=end
