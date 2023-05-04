/*
 * @lc app=leetcode id=649 lang=c
 *
 * [649] Dota2 Senate
 */

// @lc code=start
// Solution 2: queue
typedef struct
{
    int capacity;
    int push_index;
    int pop_index;
    int *arr_val;
} QUEUE;

QUEUE *init_queue(int n)
{
    QUEUE *q = malloc(sizeof(QUEUE));
    q->capacity = n;
    q->push_index = 0;
    q->pop_index = 0;
    q->arr_val = calloc(n, sizeof(int));
    return q;
}

void push_queue(int input, QUEUE *q)
{
    q->arr_val[q->push_index++] = input;
}

int pop_queue(QUEUE *q)
{
    return q->arr_val[q->pop_index++];
}

void free_queue(QUEUE *q)
{
    free(q->arr_val);
    free(q);
}

char *predictPartyVictory(char *senate)
{
    int s_len = strlen(senate);
    QUEUE *q = init_queue(2 * s_len);
    int cnt[2] = {0}, ban[2] = {0};
    int x;
    for (int i = 0; i < s_len; i++)
    {
        x = senate[i] == 'R' ? 1 : 0;
        cnt[x]++;
        push_queue(x, q);
    }
    while (cnt[0] && cnt[1])
    {
        x = pop_queue(q);
        if (ban[x])
        {
            ban[x]--;
            cnt[x]--;
        }
        else
        {
            ban[1 - x]++;
            push_queue(x, q);
        }
    }
    return cnt[1] ? "Radiant" : "Dire";
}
// @lc code=end

// Note : greedy / queue

// Solution 1: greedy
// char *predictPartyVictory(char *senate)
// {
//     int s_len = strlen(senate);
//     int mark = 0;
//     int r_count = 0, d_count = 0;
//     for (int i = 0; i < s_len; i++)
//     {
//         if (senate[i] == 'R')
//             r_count++;
//         else
//             d_count++;
//     }
//     while (r_count > 0 && d_count > 0)
//     {
//         for (int i = 0; i < s_len; i++)
//         {
//             if (senate[i] == 'R')
//             {
//                 if (mark++ < 0)
//                 {
//                     senate[i] = '1';
//                     r_count--;
//                 }
//             }
//             else if (senate[i] == 'D')
//             {
//                 if (mark-- > 0)
//                 {
//                     senate[i] = '1';
//                     d_count--;
//                 }
//             }
//         }
//     }
//     return r_count > 0 ? "Radiant" : "Dire";
// }