#include <iostream>
#include <vector>

using namespace std;

int v[102][102];
int k[102];
char t[101];
vector<int> vl[101];
int n;

int haku(int s) {
    k[s] = 1;
    if(s == n)return 1;
    for (int i = 1; i <= n; i++) {
        if(!k[i] && v[s][i] > 0) {
            if(haku(i)){
                v[s][i] -= 1;
                v[i][s] += 1;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(0);
    int m,a,b;
    cin >> n >> m;
    n++;
    for (int i = 1; i < n; i++) {
        cin >> t[i];
        if(t[i] == 'E') {
            v[0][i] = 1;
            vl[0].push_back(i);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if(t[a] == 'V') swap(a,b);
        if(t[a] != t[b]) {
            v[a][b] = 1;
            vl[a].push_back(b);
        }
        if(t[a] == 'V') v[a][n] = 1;
        if(t[b] == 'V') v[b][n] = 1;
    }
    int p = 0;
    while(haku(0)) {
        p++;
        for (int i = 0; i <= n; i++) k[i] = 0;
    }
    for (int i = 0; i <= n; i++) k[i] = 0;
    cout << p << endl;
    for(auto s: vl[0]) {
        if(k[s]) continue;
        for(auto u: vl[s]) {
            if(k[u]) continue;
            if(!v[s][u]) {
                k[s] = k[u] = 1;
                cout << s << " " << u << endl;
            }
        }
    }
    return 0;
}
