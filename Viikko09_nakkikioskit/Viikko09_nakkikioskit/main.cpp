#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> v[100001];
int c[100001];
int dp[100001];
int taso[100001];
int esi[17][100001];

void haku(int s, int e, int k, int t) {
    if(c[s]) k++;
    dp[s] = k;
    taso[s] = t;
    esi[0][s] = e;
    for(auto u: v[s]) {
        if(u == e) continue;
        haku(u,s,k,t+1);
    }
}

int f(int x, int k) {
    for (int i = 16; i >= 0; i--) {
        while(k >= (1 << i)) {
            x = esi[i][x];
            k -= (1 <<i);
        }
    }
    return x;
}

int main() {
    cin.sync_with_stdio(0);
    int n,a,b,k,q, A,B;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> k;
    for (int i = 0; i<k; i++) {
        cin >> a;
        c[a] = 1;
    }
    haku(1,0,0,1);
    for (int i = 1; i < 17; i++) {
        for (int j = 2; j <= n; j++) {
            esi[i][j] = esi[i-1][esi[i-1][j]];
        }
    }
    cin >> q;
    for (int i = 0; i<q; i++) {
        cin >> a >> b;
        if(taso[a] > taso[b]) swap(a,b);
        A = a;
        B = b;
        b = f(b, taso[b]-taso[a]);
        if(a == b) {
            cout << dp[B]-dp[A] +c[A]<< endl;
            continue;
        }
        for (int j = 16; j >= 0; j--) {
            if(esi[j][a] != esi[j][b]) {
                a = esi[j][a];
                b = esi[j][b];
            }
        }
        a = esi[0][a];
        cout << dp[A]+dp[B]-2*dp[a]+c[a] << endl;
    }
    return 0;
}
