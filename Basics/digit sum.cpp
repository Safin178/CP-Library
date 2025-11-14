ll ds(ll x)
{
    ll sum = 0;
    while (sum > 0)
    {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

// 234=9