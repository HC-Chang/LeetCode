unsigned long hash(unsigned char *str, int count)
{
    unsigned long hash = 5381;
    for (int i = 0; i < count; i++)
        hash = ((hash << 5) + hash) + str[i];

    return hash;
}