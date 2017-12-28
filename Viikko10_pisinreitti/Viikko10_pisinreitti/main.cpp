#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> v[100001];
int k[100001];
vector<int> t;
int d[100001];
bool syk = 0;

void haku(int s){
    k[s] = 1;
    for (auto u: v[s]) {
        if(k[u] == 1) syk = 1;
        if(k[u] == 0) haku(u);
    }
    k[s] = 2;
    t.push_back(s);
}

int main() {
    cin.sync_with_stdio(0);
    int n,m,a,b,M= 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if(!k[i]) {
            haku(i);
        }
    }
    if(syk) {cout << "oo\n"; return 0;}
    for(auto it = --t.end(); it >= t.begin(); it--) {
        for(auto u: v[*it]) {
            d[u] = max(d[u], d[*it]+1);
            M = max(M,d[u]);
        }
    }
    cout << M << endl;
    return 0;
}
