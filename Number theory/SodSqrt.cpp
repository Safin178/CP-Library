#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll SOD(ll n) { //! O(Sqrt(N))
  ll sod = 1;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ll cur = i;
      while (n % i == 0) {
        cur *= i, n /= i;
      }
      cur = (cur - 1) / (i - 1);
      sod *= cur;
    }
  }
  if (n != 1) sod *= (n + 1);
  return sod;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n = 100;

    cout<<"sigma "<<SOD(n)<<endl;

    return 0;
}