bool cmp(pair<int, int> A, pair<int, int> B) // pair compare
{
    if (A.first == B.first)
        return (A.second > B.second);
    //! if A.second is Larger than A will come before B
    return (A.first < B.first);
    //! if A.first is smaller than A will come before B
}



int double_comp(ld a, ld b) //compare between 2 double
{
    if (fabs(a - b) <= eps)
        return 0;
    return a < b ? -1 : 1;
    //! dbl cmp return 0 when a==b, -1 if a<b ,, 1 if a>b
}
