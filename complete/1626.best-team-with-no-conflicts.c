/*
 * @lc app=leetcode id=1626 lang=c
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
#define max(a, b) (a > b ? a : b)

typedef struct
{
    int age;
    int score;
} DATA;

int sort(void *a, void *b)
{
    DATA *aa = (DATA *)a;
    DATA *bb = (DATA *)b;
    if (aa->age != bb->age)
        return aa->age - bb->age;
    else
        return aa->score - bb->score;
}

int bestTeamScore(int *scores, int scoresSize, int *ages, int agesSize)
{
    int n = scoresSize;
    int dp[1000] = {0};
    DATA *data = calloc(n, sizeof(DATA));
    for (int i = 0; i < n; i++)
    {
        data[i].age = ages[i];
        data[i].score = scores[i];
    }
    qsort(data, n, sizeof(DATA), sort);

    dp[0] = data[0].score;
    for (int i = 1; i < n; i++)
    {
        dp[i] = data[i].score;
        for (int j = 0; j < i; j++)
        {
            if ((data[j].age < data[i].age && data[j].score <= data[i].score) || data[j].age == data[i].age)
                dp[i] = max(dp[i], (dp[j] + data[i].score));
        }
    }

    int r = 0;
    for (int i = 0; i < n; i++)
        r = max(r, dp[i]);

    free(data);

    return r;
}

// @lc code=end
