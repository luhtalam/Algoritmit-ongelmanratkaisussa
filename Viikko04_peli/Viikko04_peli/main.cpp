#include <iostream>
#include <vector>

#define F first
#define S second

using namespace std;

pair<int, int[10]> d[10][10][3];
vector<pair<int,int>> g;

int main() {
    cin.sync_with_stdio(0);
    int n, t, x, v, k;
    cin >> n >> t >> x;
    g.push_back({0,t});
    for (int i = 1; i<=n; i++) {
        cin >> v >> k;
        g.push_back({k,v});
        for (int j = 0; j < 3; j++) {
            d[t][i][j].F = v;
            d[t][i][j].S[i] = 1;
        }
    }
    int max,curr, idx;
    for (int j = t-1; j > -1; j--) { //kierros
        for (int i = 1; i <= n; i++) { //ruutu
            for (int a = -1; a < 2; a++) { //suunta
                max = 0;
                idx = 0;
                for (int b = 0; b < 3; b++) { //edelliset
                    if(i+a < 1 || i+a > n) continue;
                    curr = d[j+1][i+a][b].F;
                    if(!d[j+1][i+a][b].S[i] && g[i].F <= j) curr += g[i].S;
                    if(curr >= max) {
                        max = curr;
                        idx = b;
                    }
                }
                d[j][i][1+a].F = max;
                for (int c = 0; c < 101; c++) {
                    d[j][i][1+a].S[c] = d[j+1][i+a][idx].S[c];
                }
                d[j][i][1+a].S[i] = 1;
            }
        }
    }
    int e = 0;
    int ans = d[1][x+e][0].F;
    if (d[1][x+e][1].F > ans) ans = d[0][x+e][1].F;
    if (d[1][x+e][2].F > ans) ans = d[0][x+e][2].F;
    cout << ans << "\n";
}
