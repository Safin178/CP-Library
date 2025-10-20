#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;



ll NOD(ll n) { //! O(Sqrt(N))
  ll nod = 1;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ll p = 0;
      while (n % i == 0) {
        n /= i;
        p++;
      }
      nod *= (p + 1);
    }
  }
  if (n != 1)
    nod *= 2;
  return nod;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n = 100;
   

    cout << NOD(n) << endl;

    return 0;
}