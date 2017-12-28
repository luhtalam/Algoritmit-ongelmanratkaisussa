#include <iostream>
#define M 1000000007;

long dp[2001][1001];

using namespace std;

long binom(int a, int b) {
    if(b == 0 || a == b) return 1;
    if(dp[a][b]) return dp[a][b];
    long c = binom(a-1,b-1)+ binom(a-1,b);
    c %= M;
    dp[a][b] = c;
    return c;
}

int main() {
    cin.sync_with_stdio();
    int n, m;
    cin >> n >> m;
    cout << binom(n+m-1,m) << endl;
    return 0;
}
