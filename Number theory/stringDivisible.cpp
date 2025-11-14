
/*
is large number divisible by int or not
*/

int is_div(string a, int b)
{
    int j = 0;
    if (a[0] == '-')
        j = 1;
    if (b < 0)
        b = abs(b);
    ll rim = 0;
    for (; j < sz(a); j++)
    {
        rim = rim * 10 + (a[j] - '0');
        rim %= b;
    }
    return rim; // if rim=0 divisible else not
}
