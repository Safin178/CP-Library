/**
 * Author: 
 * Date: 2025-11-14
 * License: CC0
 * Source: 
 * Description: Precomputes Number of Divisors (NOD) and Sum of Divisors (SOD) 
 *  for all numbers up to nmax using a modified sieve. Then prints tau(n) 
 *  and sigma(n) for a given n.
 * Usage:
 *  sieve();
 *  cout << NOD[100] << " " << SOD[100];
 * Time: O(N log N)
 * Memory: O(N)
 * Status: 
 */
#pragma once

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

    ll n = 100;

    cout<<"tau "<<NOD[n]<<endl;
    cout<<"sigma "<<SOD[n]<<endl;

    return 0;
}
