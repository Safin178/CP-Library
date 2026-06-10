#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

// (a*b)%mod without overflow
ull mod_mul(ull a, ull b, ull mod)
{
    ull res = 0;

    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;

        a = (a + a) % mod;
        b >>= 1;
    }

    return res;
}

ull mod_pow(ull a, ull d, ull mod)
{
    ull res = 1;

    while (d)
    {
        if (d & 1)
            res = mod_mul(res, a, mod);

        a = mod_mul(a, a, mod);
        d >>= 1;
    }

    return res;
}


// Miller Rabin
bool isPrime(ull n)
{
    if (n < 2) return false;

    for (ull p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL})
    {
        if (n % p == 0)
            return n == p;
    }

    ull d = n - 1;
    int s = 0;

    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }


    // deterministic for 64 bit
    for (ull a : {2ULL, 325ULL, 9375ULL, 28178ULL,
                  450775ULL, 9780504ULL, 1795265022ULL})
    {
        if (a % n == 0)
            continue;

        ull x = mod_pow(a, d, n);

        if (x == 1 || x == n - 1)
            continue;


        bool ok = false;

        for (int r = 1; r < s; r++)
        {
            x = mod_mul(x, x, n);

            if (x == n - 1)
            {
                ok = true;
                break;
            }
        }

        if (!ok)
            return false;
    }

    return true;
}


// Pollard Rho
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


ull pollard(ull n)
{
    if (n % 2 == 0)
        return 2;

    while (true)
    {
        ull c = uniform_int_distribution<ull>(1, n - 1)(rng);

        ull x = uniform_int_distribution<ull>(0, n - 1)(rng);
        ull y = x;

        ull d = 1;


        auto f = [&](ull v)
        {
            return (mod_mul(v, v, n) + c) % n;
        };


        while (d == 1)
        {
            x = f(x);
            y = f(f(y));

            ull diff = x > y ? x - y : y - x;

            d = __gcd(diff, n);
        }


        if (d != n)
            return d;
    }
}


void factor(ull n, vector<ull>& v)
{
    if (n == 1)
        return;

    if (isPrime(n))
    {
        v.push_back(n);
        return;
    }


    ull d = pollard(n);

    factor(d, v);
    factor(n / d, v);
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int T;
    cin >> T;


    while (T--)
    {
        ull X, K;
        cin >> X >> K;

        // if(isPrime(K)) 
        // {
        //     cout <<  K <<
        // }
          if (K == 1 || (X == 1 and K == 0))
        {
            cout << "=\n";
            continue;
        }

        if(K == 0)
        {
            cout << ">\n";
            continue;
        }


      


        vector<ull> fac;

        factor(K, fac);


        sort(fac.begin(), fac.end());

        // for(auto u : fac) cout << u << ' ';

        fac.erase(unique(fac.begin(), fac.end()), fac.end());

        //   for(auto u : fac) cout << u << ' ';


        bool bigger = false;


        for (ull p : fac)
        {
            if (X % p != 0)
            {
                bigger = true;
                break;
            }
        }


        if (bigger)
            cout << "<\n";
        else
            cout << "=\n";
    }

    return 0;
}
// https://toph.co/p/a-gre-themed-contest-problem
