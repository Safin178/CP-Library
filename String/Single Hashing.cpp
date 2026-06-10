const ll nmax = 1e6 + 10;
const ll prime = 1e9 + 7;
const ll base = 1e6+3;

ll power[nmax];
ll H[nmax];

void precal()
{
    power[0] = 1;
    for(ll i = 1; i < nmax; i++) power[i] = (power[i - 1] * base) % prime; 
}

void buildhash(string &s)
{
    H[0] = s[0];
    for(ll i = 1; i < sz(s) ; i++) H[i] = (H[i - 1] * base + s[i]) % prime;
}

ll gethash(ll L, ll R)
{
    if(L == 0) return H[R];

    ll ret = (H[R] - H[L-1] * power[R-L+1]) % prime;
    if(ret < 0) ret += prime;
    return ret;
}

ll fasthash(string &s)
{
    ll hasht = s[0];
    for(ll i = 1;  i < sz(s) ; i++) hasht = (hasht * base + s[i]) % prime;

    return hasht;
}

//H(A*B) ≠ H(A) * H(B) 
