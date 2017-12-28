#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int p[100001];
long jaa[100001];
long potkut[100001];
vector<int> v[100001];

void haku(int s) {
    potkut[s] = p[s];
    jaa[s] = 0;
    for(auto u: v[s]) {
        haku(u);
        potkut[s] += jaa[u];
        jaa[s] += max(potkut[u], jaa[u]);
    }
}

int main() {
    cin.sync_with_stdio(0);
    int n,a;
    cin >> n;
    for (int i = 1; i <=n; i++) {
        cin >> p[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> a;
        v[a].push_back(i);
    }
    haku(1);
    cout << max(potkut[1],jaa[1]) << endl;
    return 0;
}
