#include <bits/stdc++.h>
using namespace std;
/*Upobir 
int phi[100000+5];
bool mark[100000+5];

void sieve(){
    for(int i = 1; i<=100000; i++)
        phi[i] = i;

    for(int i = 2; i<=100000; i++){
        if(mark[i])
            continue;
        phi[i] = i-1;    //! i is prime => φ(i) = i-1
        for(int j = i+i; j<=100000; j+=i){
            mark[j] = true;

            phi[j] = phi[j] - phi[j]/i;
        }
    }
}
*/

const int N = 1e5 + 9;
int phi[N];
void etf() {
  for (int i = 1; i < N; i++) phi[i] = i;
  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i) phi[j] -= phi[j] / i;
    }
  }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    etf();

    cout<<phi[97]<<endl;

    return 0;
}
