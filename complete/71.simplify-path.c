/*
 * @lc app=leetcode id=71 lang=c
 *
 * [71] Simplify Path
 */

// @lc code=start
typedef struct
{
    int size;
    int cur;
    char **arr;
} STACK;

STACK *init_stack(int size)
{
    STACK *obj = malloc(sizeof(STACK));
    obj->size = size;
    obj->cur = -1;
    obj->arr = malloc(sizeof(char *) * size);
    return obj;
}

bool is_empty_stack(STACK *obj)
{
    return (obj->cur == -1 ? true : false);
}

void push_stack(STACK *obj, char *ptr)
{
    obj->cur += 1;
    obj->arr[obj->cur] = ptr;
}

char *pop_stack(STACK *obj)
{
    if (is_empty_stack(obj))
        return NULL;

    obj->cur -= 1;
    return obj->arr[obj->cur + 1];
}

void free_stack(STACK *obj)
{
    free(obj->arr);
    free(obj);
}

void update_path_bottom_upstack(STACK *s, char *path)
{
    for (int i = 0; i <= s->cur; i++)
    {
        strcat(path, "/");
        strcat(path, s->arr[i]);
    }
}

char *simplifyPath(char *path)
{
    int len = strlen(path);
    if (len == 0)
        return path;

    STACK *s = init_stack(len + 1);
    char *tmp = calloc(len + 1, sizeof(char));
    strcpy(tmp, path);

    char *delim = "/";
    char *pch = NULL;
    pch = strtok(tmp, delim);
    while (pch != NULL)
    {
        if (strlen(pch) == 2 && !strcmp(pch, ".."))
            pop_stack(s);
        else if (strlen(pch) != 1 || strcmp(pch, "."))
            push_stack(s, pch);
        pch = strtok(NULL, delim);
    }

    memset(path, 0, sizeof(char) * len);
    if (is_empty_stack(s))
        strcat(path, "/");
    else
        update_path_bottom_upstack(s, path);

    free(tmp);
    free_stack(s);
    return path;
}

// @lc code=end
