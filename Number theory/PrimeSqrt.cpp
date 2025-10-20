#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long int n){
    if(n == 1)
        return false;
    for(long long int i = 2; i*i <= n; i++){        
        if(n % i == 0)
            return false;
    }
    return true;
}
// O(sqrt(n))

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout<<is_prime(1000000007)<<endl;

    return 0;
}
