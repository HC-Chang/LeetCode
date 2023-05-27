// Greatest Common Divisor
// Similar Questions: 1979

int gcd(int a, int b)
{
    if(a%b)
        return gcd(b,a%b);
    else
        return b;
}
