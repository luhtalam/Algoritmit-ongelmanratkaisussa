#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001];
int c[100001];
long d[100001];

void haku(int s, int e) {
    c[s] = 1;
    for(auto u: v[s]) {
        if(u == e) continue;
        haku(u,s);
        c[s] += c[u];
        d[s] += d[u] + c[u];
    }
}

void haku2(int s, int e) {
    d[s] = d[e]+(c[1]-2*c[s]);
    for(auto u: v[s]) {
        if(u == e) continue;
        haku2(u,s);
    }
}

int main() {
    cin.sync_with_stdio(0);
    int n,a,b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    haku(1,0);
    for(auto u: v[1]) haku2(u,1);
    for (int i = 1; i <= n; i++) cout << d[i] << endl;
    return 0;
}
