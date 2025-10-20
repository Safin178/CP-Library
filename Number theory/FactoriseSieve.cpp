

const int M = 1000000; // max : 9e7
vector<int>primes;
bool marked[M];
bool isprime(int n) {
  if (n == 2)
    return true;
  if (n < 2 || n % 2 == 0)
    return false;
  return marked[n] == false;
}
void sieve(ll n) { // O(n log log n)
  for (ll i = 3; i * i <= n; i += 2) {
    if (marked[i] == false) // i is a prime
    {
      for (ll j = i * i; j <= n; j += i) {
        marked[j] = true;
      }
    }
  }
     for (int i = 0; i < n; i++) { 
    if (isprime(i)) {
        primes.push_back(i);
    }
  }
}

vector < int > factor(int n) {
  vector < int > fact;
  for (int i = 0; primes[i] * primes[i] <= n; i++) {
    while (n % primes[i] == 0) {
      n /= primes[i];
      fact.pb(primes[i]);// cnt korbo and comment
    }
  }
  if (n > 1) fact.pb(n);
  return fact;
  // primes[i] is a , loop cnt is p, a^p
}
