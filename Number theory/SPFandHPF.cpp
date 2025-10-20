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