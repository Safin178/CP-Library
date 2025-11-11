ll bin_exp(ll a, ll n) //O(log(n))
{
  // a ^ n
  ll r = 1LL;
  int m = 1000000007;
  // Delete % m if we don't need it
  while (n) {
    if (n & 1) r = (r * a) % m, n--;
    else a = (a * a) % m, n /= 2LL;
  }
  return r;
}

const int mod2 = 1e9 + 7;
inline ll MOD(ll a){ return (a % mod2 + mod2) % mod2; }
inline ll modAdd(ll a, ll b) { return MOD(MOD(a) + MOD(b)); }
inline ll modSub(ll a, ll b) { return MOD(MOD(a) - MOD(b)); }
inline ll modMul(ll a, ll b) { return MOD(MOD(a) * MOD(b)); }
inline ll modInv(ll a) { return bin_exp(a, mod2 - 2); } // buji na
// this mod is bit slow, ans %= mod(slow) or ans -= ans / mod * mod