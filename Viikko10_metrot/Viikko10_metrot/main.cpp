#include <iostream>
#include <vector>

using namespace std;

int f[100001];
vector<int> r[100001];
int k[100001];
int ans[100001];
vector<int> sykli;

int haku(int s) {
    k[s] = 1;
    int c = 1;
    int l, M = 0;
    for(auto u: r[s]) {
        if(k[u]) continue;
        l = haku(u);
        if(l > M) swap(l,M);
        for (int i = 0; i < l; i++) {
            ans[i] += l-i;
        }
    }
    return c+M;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie();
    int n,q,a,b,c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        f[i] = a;
        r[a].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if(k[i]) continue;
        sykli.clear();
        a = f[i];
        b = f[f[i]];
        while (a != b) {
            a = f[a];
            b = f[f[b]];
        }
        sykli.push_back(a);
        k[a] = 1;
        b = f[a];
        c = 1;
        while (a != b) {
            sykli.push_back(b);
            k[b] = 1;
            b = f[b];
            c++;
        }
        for (int i = 0; i <= n; i++) {
            ans[i] += c;
        }
        for(auto s: sykli) {
            a = haku(s)-1;
            for (int i = 0; i < a; i++) {
                ans[i] += a-i;
            }
        }
    }
    cin >> q;
    for (int i = 0; i<q; i++) {
        cin >> a;
        if(a > n) cout << ans[n] << endl;
        else cout << ans[a] << endl;
    }
    return 0;
}
