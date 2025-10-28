int l = 0,r = n; 
while(l<=r) 
{ 
    int m = (l+r) / 2; 
    if(x == a[m]) 
    { 
        // ! work 
    } 
    else if(x<a[m]) r = m-1; 
    else l=m+1; 
} 
! Lower bound: maximum index which in not greater 
than X / first jekhane X insert kora jabe 
    int l = -1; //a[l]<=x 
    int r = n; //a[r]>x 
    while (l + 1 < r) 
    { 
        int m = (l + r) / 2; 
        if (a[m] >= x) r = m; 
        else l = m; 
    } 
    cout << r << endl; 
    cout << lower_bound(a.begin(), a.end(), x) - 
a.begin(); 
! Upper bound: minimum index which in not less than X / last jekhane X insert kora jabe 
    int l = -1; //a[l]<x 
    int r = n; //a[r]>=x 
    while (l + 1 < r) 
    { 
        int m = (l + r) / 2; 
        if (a[m] > x) r = m; 
        else l = m; 
    } 
    cout << r << endl; 
    cout << upper_bound(a.begin(), a.end(), x) - 
a.begin() << endl; 
*/ 