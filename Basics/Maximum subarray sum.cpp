ll kadane_algo(const vector<ll> & v, ll n) { 
  ll temp = 0, res = 0; 
  for (ll i = 0; i < n; i++) { 
    temp += v[i]; 
    if (temp < 0) temp = 0; 
    res = max(res, temp); 
  } 
  return res; } 