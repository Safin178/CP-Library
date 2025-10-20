#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 1e5 + 10;

int NOD[nmax];
int SOD[nmax];

void sieve(){ //! O(NlogN)
    for(int i = 1; i<nmax; i++){
        for(int m = i; m < nmax; m += i){
            NOD[m]++;
            SOD[m] += i;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
//
    ll n = 100;

    cout<<"tau "<<NOD[n]<<endl;
    cout<<"sigma "<<SOD[n]<<endl;

    return 0;
}
