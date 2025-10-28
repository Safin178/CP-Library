
//getting all possible subset of k elements(k elements has 2^k subsets ) 
void bitmask(int k) //! O(k*(2^k)) 
{ 
  for (int j = 0; j < (1 << k); j++) { 
    for (int i = 0; i < k; i++) { 
      if (j & (1 << i)) { 
        //* take the i-th element 
      } 
    } 
  } 
}

//bitwise basics 0 - based index
// Bitwise
#define cnt_bits(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)

ll set0(ll n, ll k){ 
 n = (n | (1LL << k)) ^ (1LL << k); 
    return n; 
} 
ll set1(ll n, ll k){ 
    n = (n | (1LL << k)); 
    return n; 
} 
ll togl(ll n, ll k){ 
    return (n ^ (1LL << k)); 
} 
bool is_set(ll n, ll k){ 
    return (n & (1LL << k)); 
} 


