mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll gen_random(ll l, ll r){
return uniform_int_distribution<ll>(l, r)(rng);
}

// gen_random(l, r); // random number dei l to r er modde
shuffle(all(v), rng); // shuffle fun() vector ke randomly suffle kore

