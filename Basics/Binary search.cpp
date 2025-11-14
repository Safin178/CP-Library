
! binary search normal
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

! Lower bound: maximum index which in not greater than X / first jekhane X insert kora jabe 
    int l = -1; //a[l]<=x 
    int r = n; //a[r]>x 
    while (l + 1 < r) 
    { 
        int m = (l + r) / 2; 
        if (a[m] >= x) r = m; 
        else l = m; 
    } 
    cout << r << endl; 
    cout << lower_bound(a.begin(), a.end(), x) - a.begin(); 


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
    cout << upper_bound(a.begin(), a.end(), x) - a.begin() << endl;



#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {

    double lo=0, hi=2e18;
    int it=100;
    while(it--){
        double mid=(lo + hi)/2;
                
        //! work here

        if( /*condition*/ ) hi=mid;
        else lo=mid;
    }
    
    cout << fixed << setprecision(12) << hi << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t; cin >> t;
    // while (t--) 
    solve();
}
