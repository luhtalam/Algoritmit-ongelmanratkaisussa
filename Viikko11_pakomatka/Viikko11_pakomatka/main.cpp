#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int v[101][101];
int k[101];
vector<int> vl[101];
vector<int> vl2[101];
vector<int> t;
long c;
int n;

int flow(int s, int minim) {
    k[s] = 1;
    if(s == n)return minim;
    for (auto i: vl2[s]) {
        if(!k[i] && v[s][i] >= c) {
            if(int f = flow(i, min(minim,v[s][i]))){
                v[s][i] -= f;
                v[i][s] += f;
                return f;
            }
        }
    }
    return 0;
}

void haku(int s) {
    k[s] = 1;
    t.push_back(s);
    for (int i = 1; i <= n; i++) {
        if(!k[i] && v[s][i]) haku(i);
    }
}

int main() {
    cin.sync_with_stdio(0);
    int m,a,b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a][b] = c;
        vl[a].push_back(b);
        vl2[b].push_back(a);
        vl2[a].push_back(b);
    }
    c = 0;
    long total = 0;
    for(auto u: vl[1]) c+= v[1][u];
    while(c > 0) {
        if(int f = flow(1,1e9)) total += f;
        else c /= 2;
        for (int i = 1; i <= n; i++) k[i] = 0;
    }
    for (int i = 1; i <= n; i++) k[i] = 0;
    haku(1);
    vector<pair<int,int>> vt;
    for(auto s: t) {
        for(auto u: vl[s]) {
            if(!k[u] && !v[s][u]) {
                vt.push_back({s,u});
            }
        }
    }
    cout << total << endl;
    cout << vt.size() << endl;
    for(auto u: vt) {
        cout << u.first << " " << u.second << endl;
    }
    return 0;
}
