#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v[101][101];
int k[101];
vector<int> vl[101];
long c,virtaus = 0;
int n;

int haku(int s, int minim) {
    k[s] = 1;
    if(s == n)return minim;
    for (auto i: vl[s]) {
        if(!k[i] && v[s][i] >= c) {
            if(int f = haku(i, min(minim,v[s][i]))){
                v[s][i] -= f;
                v[i][s] += f;
                return f;
            }
        }
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(0);
    int m,a,b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a][b] += c;
        vl[a].push_back(b);
        vl[b].push_back(a);
    }
    c = 0;
    for (int i = 2; i <= n; i++) c += v[1][i];
    while(c > 0) {
        if(int f = haku(1,1e9)) virtaus += f;
        else c /=2;
        for (int i = 1; i <= n; i++) k[i] = 0;
    }
    cout << virtaus << endl;
    return 0;
}
