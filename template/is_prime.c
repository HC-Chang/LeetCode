// Is Prime

bool is_prime(int n)
{
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
            return false;
        i++;
    }
    return n >= 2;
}
