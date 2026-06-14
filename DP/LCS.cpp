#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int n, m;
string s, p;

int f(int i, int j) { // n^2
    if (i == n || j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = max(f(i + 1, j), f(i, j + 1));
    if (s[i] == p[j])
        ans = max(ans, 1 + f(i + 1, j + 1));

    return dp[i][j] = ans;
}

void printLCS(int i, int j) {
    if (i == n || j == m) return;

    if (s[i] == p[j]) {
        printLCS(i + 1, j + 1);
        cout << s[i];  // print on way back = correct order
    } else if (dp[i + 1][j] >= dp[i][j + 1]) {
        printLCS(i + 1, j);
    } else {
        printLCS(i, j + 1);
    }
}

int main() {
    cin >> s >> p;
    n = s.size();
    m = p.size();

    memset(dp, -1, sizeof(dp));

    cout << "LCS length: " << f(0, 0) << "\n";
    cout << "LCS string: ";
    printLCS(0, 0);
    cout << "\n";
}