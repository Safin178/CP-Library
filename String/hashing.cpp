const int nmax = 1e6 + 9;

const ll prime1 = 1e9 + 7;
const ll prime2 = 1e9 + 9;

const ll BASE1 = 1000003;
const ll BASE2 = 10000019;

pair<ll,ll> power[nmax];

void precal() {
    power[0] = {1, 1};

    for(int i = 1; i < nmax; i++) {
        power[i].first = (power[i - 1].first * BASE1) % prime1;
        power[i].second = (power[i - 1].second * BASE2) % prime2;
    }
}

struct Hashing {

    string s;
    int n;

    vector<pair<ll,ll>> H;

    Hashing() {}

    Hashing(string _s) {
        s = _s;
        n = s.size();

        H.resize(n);

        H[0] = {s[0], s[0]};

        for(int i = 1; i < n; i++) {

            H[i].first = (H[i - 1].first * BASE1 + s[i]) % prime1;

            H[i].second = (H[i - 1].second * BASE2 + s[i]) % prime2;
        }
    }

    pair<ll,ll> get_hash(int l, int r) {
        // 0-indexed

        pair<ll,ll> ret;

        if(l == 0) {
            return H[r];
        }

        ret.first = (H[r].first - H[l - 1].first * power[r - l + 1].first) % prime1;
        if(ret.first < 0) ret.first += prime1;

        ret.second = (H[r].second - H[l - 1].second * power[r - l + 1].second) % prime2;
        if(ret.second < 0) ret.second += prime2;

        return ret;
    }
};

// ! For unordered_map to avoid tle , unordered_map<pll,ll, hash_pair> m 
// ! avg O(1) find , insert 
 
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1ll);
    }
};

// ! tested for gp_hash_table , gp_hash_table<pll,ll, hash_pair> m;
// better than unordered map + fast 
// include pbds headers
struct hash_pair {
    size_t operator()(const pll& p) const {
        return p.first ^ (p.second << 1);
    }
};