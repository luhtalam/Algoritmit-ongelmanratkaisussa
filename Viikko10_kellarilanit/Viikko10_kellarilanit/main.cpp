#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> v1[100001];
vector<int> v2[100001];
int k[100001];
vector<int> list;
int c;

void haku1(int s) {
    k[s] = 1;
    for(auto u: v1[s]) {
        if(!k[u]) haku1(u);
    }
    list.push_back(s);
}

void haku2(int s) {
    k[s] = 2;
    for(auto u: v2[s]) {
        if(k[u] != 2) haku2(u);
    }
    c++;
}

int main() {
    cin.sync_with_stdio(0);
    int n,m,a,b, M = 0;
    cin >> n >>m;
    for (int i = 0; i<m; i++) {
        cin >> a >> b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if(!k[i]) haku1(i);
    }
    for (auto it = --list.end(); it >= list.begin(); it--) {
        c = 0;
        if(k[*it] != 2) haku2(*it);
        M = max(M,c);
    }
    cout << M << endl;
    return 0;
}
