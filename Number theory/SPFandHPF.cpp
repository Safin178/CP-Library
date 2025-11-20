// not tested might have bugs, have to add code later 
also for factorize

// const int M = 1e6 + 1;
// bool isPrime[M];
// int LowPrime[M];
// int HighPrime[M];
// void sieveLH(int n)  //! High Prime Low Prime //O(n log log n) 
// {
//   for (int i = 2; i * i <= n; i++) {

//     if (isPrime[i] == false) {

//       LowPrime[i] = HighPrime[i] = i;
//       for (int j = i + i; j <= n; j += i) {

//         isPrime[j] = true;
//         HighPrime[j] = i;
//         if (LowPrime[j] == 0) LowPrime[j] = i;

//       }

//     }
//   }
// }

int const MAXN = (int)1e7 + 5;
vector<int> spf(MAXN + 1, 1);
void sieve()
{
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { 
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1)
                    spf[j] = i;
            }
        }
    }
}

vector<int> getFactorization(int x) // with spf
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}