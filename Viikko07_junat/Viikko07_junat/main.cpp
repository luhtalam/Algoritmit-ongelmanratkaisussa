#include <iostream>
#include <math.h>

using namespace std;

int N = (1 << 17);
pair<int,int> p[(1 << 18)];
int asemat[100001];
long dp[100001];
int n;

int maksimi(int a, int b) {
    if(b == n) return b;
    a += N; b+=N;
    pair<int,int> pa = p[a];
    while (a <= b) {
        if (a%2 == 1) pa = max(pa, p[a++]);
        if (b%2 == 0) pa = max(pa, p[b--]);
        a = (a >> 1); b = (b >> 1);
    }
    return pa.second-N;
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n;
    int a;
    for (int i = N+1; i < N+n; i++) {
        cin >> a;
        p[i] = {a,i};
        asemat[i-N] = a;
    }
    for (int i = N-1; i > 0; i--) {
        p[i] = max(p[(i << 1)], p[(i << 1)+1]);
    }
    long vast = 0;
    for (int i = n-1; i > 0; i--) {
        int j = maksimi(i, asemat[i]);
        dp[i] = n + dp[j] + j - i- asemat[i];
//        dp[i] = (asemat[i]-i) + dp[j] + (n-asemat[i]) - (asemat[i]-j);
        vast += dp[i];
    }
    cout << vast << endl;
    return 0;
}
