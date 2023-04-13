/*
 * @lc app=leetcode id=946 lang=c
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
typedef struct
{
    int index;
    int *arr;    
}STACK;

STACK* init_stack(int n)
{
    STACK *s = malloc(sizeof(STACK));
    s->index = 0;
    s->arr = calloc(n, sizeof(int));
    return s;
}

void push_stack(int val, STACK* s)
{
    s->arr[s->index++] = val;
}

void pop_stack(STACK* s)
{
    s->index--;
}

bool is_empty_stack(STACK* s)
{
    return s->index == 0;
}

void free_stack(STACK* s)
{
    free(s->arr);
    free(s);
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    if(!memcmp(pushed, popped, pushedSize*sizeof(int)))
        return true;
    STACK *s = init_stack(pushedSize);
    
    int popped_index = 0;
    push_stack(pushed[0], s);
    for(int i = 1; i< pushedSize; i++)
    {
        while(s->index > 0 &&  s->arr[s->index-1] == popped[popped_index])
        { 
            pop_stack(s);
            popped_index++;
        }
        if(pushed[i] != popped[popped_index])
            push_stack(pushed[i], s);
        else
            popped_index++;
    }

    for(int i = popped_index; i< poppedSize; i++)
    {
        if(popped[i] == s->arr[s->index-1])
            pop_stack(s);
    }

    bool b = is_empty_stack(s);
    free_stack(s);
    return b;
}
// @lc code=end

