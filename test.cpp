// ! Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template < typename PB >
  using pbds = tree < PB, null_type, less < PB > , rb_tree_tag, tree_order_statistics_node_update > ;
#define Moon ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

// Typedefs
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl; // vvl v(n , vl(n , 0));
typedef pair<int, int> pii;
typedef priority_queue<ll, vector<ll>, greater<ll>> GPQ;
typedef long double ld;
typedef unsigned long long ull;
typedef priority_queue<ll> PQ;

// Constants
const int inf = 2e9;
const ll INF = 9e18;
const double PI = acos(-1);
const double eps = 1e-9;
const int mod = 1e9 + 7;

// Common ops
#define sz(n) (int)n.size()
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define RY {cout << "YES\n"; return;}
#define RN {cout << "NO\n"; return;}
#define ff first
#define ss second
#define nl '\n'
#define sp " "
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define forcin(p) for (auto &x : p) cin >> x
#define mem(a, b) memset(a, b, sizeof(a))

// Bitwise
#define cnt_bits(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)

// Math
#define gcd(a, b) __gcd(a, b)
#define lcm(x, y) x * (y / gcd(x, y))

// Precision
#define set_pre(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed, ios::floatfield);
#define preci(x) fixed << setprecision(x)

// Misc. functions
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define el "\n"
#define forcout(p) for (auto x : p) cout << x << ' '
#define bs binary_search

// (dx, dy for grid-based problems) 4 directions and 4 diagonal moves
const ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};  
const ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};  

// Knight's Move
const ll kdx[] = {-2, -2, -1, -1,  1,  1,  2,  2};
const ll kdy[] = {-1,  1, -2,  2, -2,  2, -1,  1};

// ======================================================================
// -------------------------- Debugger --------------------------------
template <typename F, typename S> ostream& operator<<(ostream& os, const pair<F, S>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "{"; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << *it; } return os << "}"; }
template <typename T> ostream& operator<<(ostream& os, const set<T>& v) { os << "["; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << *it; } return os << "]"; }
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& v) { os << "["; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << *it; } return os << "]"; }
template <typename T> ostream& operator<<(ostream& os, const pbds<T>& v) { os << "["; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << *it; } return os << "]"; }
template <typename F, typename S> ostream& operator<<(ostream& os, const map<F, S>& v) { os << "["; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << it->first << " = " << it->second; } return os << "]"; }
template <typename T> ostream& operator<<(ostream& os, priority_queue<T> pq) { os << "["; bool first = true; while (!pq.empty()) { if (!first) os << ", "; os << pq.top(); pq.pop(); first = false; } return os << "]"; }
template <typename T> ostream& operator<<(ostream& os, const deque<T>& dq) { os << "["; for (auto it = dq.begin(); it != dq.end(); ++it) { if (it != dq.begin()) os << ", "; os << *it; } return os << "]"; }
template <typename T> ostream& operator<<(ostream& os, queue<T> q) { os << "["; bool first = true; while (!q.empty()) { if (!first) os << ", "; os << q.front(); q.pop(); first = false; } return os << "]"; }
#define dbg(args...) do { cerr << #args << " : "; faltu(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void faltu() { cerr << endl; }
template <typename T> void faltu(T a[], int n) { for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl; }
template <typename T, typename... Args> void faltu(T arg, const Args&... rest) { cerr << arg << ' '; faltu(rest...); }
// -------------------------- END --------------------------------
// ======================================================================

int intToDay(int jd) { return jd % 7; }
int dateToInt(int y, int m, int d) {
  return 1461 * (y + 4800 + (m - 14) / 12) / 4 +
    367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
    3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 +
    d - 32075; 
}
void solve(){
  // ll n; cin >> n;  vl v(n); forcin(v);

  int x = dateToInt(2025,11,17);
  cout << intToDay(x) << nl;
    
     


}

int main(){
    Moon;

    int t=1 , tc = 1;
   // cin >> t;          
    while(t--){
       // cout << "Case " << tc++ << ": ";  //! for case
        solve();
    }

    // timeStamp;
    return 0;
}

/*
//! siv = sieve, modu = mod 
*/

/**
 * PBDS Tips:
 * - less<T>         : Sorted set (asc)
 * - less_equal<T>   : Multiset (asc)
 * - greater<T>      : Sorted set (desc)
 * - greater_equal<T>: Multiset (desc)
 *
 * name.order_of_key(k)  -> Count of elements < k
 * *name.find_by_order(k)-> k-th smallest element (0-indexed)
*/

