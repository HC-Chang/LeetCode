// Trie
// Similar Questions: 208.211

// trie api:
// - create
// - insert
// - search
// - free

#define ALPHABET_SIZE 26

typedef struct
{
    struct Trie *child[ALPHABET_SIZE];
    bool is_leaf;
} Trie;

Trie *trieCreate()
{
    Trie *new = malloc(sizeof(Trie));

    for (int i = 0; i < ALPHABET_SIZE; i++)
        new->child[i] = NULL;

    new->is_leaf = false;
    return new;
}

void trieInsert(Trie *obj, char *word)
{
    int index;
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        index = word[i] - 'a';

        if (!obj->child[index])
            obj->child[index] = trieCreate();

        obj = obj->child[index];
    }

    obj->is_leaf = true;
}

bool trieSearch(Trie *obj, char *word)
{
    int index;
    int word_len = strlen(word);
    for (int i = 0; i < word_len; i++)
    {
        index = word[i] - 'a';
        if (!obj->child[index])
            return false;

        obj = obj->child[index];
    }

    return (obj != NULL && obj->is_leaf);
}

bool trieStartsWith(Trie *obj, char *prefix)
{
    int length = strlen(prefix);
    int index;

    for (int i = 0; i < length; i++)
    {
        index = prefix[i] - 'a';

        if (!obj->child[index])
            return false;

        obj = obj->child[index];
    }

    return true;
}

void trieFree(Trie *obj)
{
    if (!obj)
        return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (obj->child[i] != NULL)
            trieFree(obj->child[i]);
    }
    free(obj);
}
