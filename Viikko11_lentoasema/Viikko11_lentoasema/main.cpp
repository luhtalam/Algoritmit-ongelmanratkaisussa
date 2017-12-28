#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long v[101][101];
int k[101];
vector<int> vl[101];
int n;
long c;

long flow(int s, long minim) {
    k[s] = 1;
    if(s == n){
        return minim;
    }
    for (auto i: vl[s]) {
        if(!k[i] && v[s][i] >= c) {
            if(long f = flow(i, min(minim, v[s][i]))){
                v[s][i] -= f;
                v[i][s] += f;
                return f;
            }
        }
    }
    return 0;
}

int main() {
    int m,a,b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if(a == -1) v[i][n+i] = 1e18;
        else v[i][n+i] = a;
        vl[i].push_back(n+i);
        vl[n+i].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[n+a][b] = 1e18;
        vl[n+a].push_back(b);
        vl[b].push_back(n+a);
    }
    c = 1e9;
    long total = 0;
    while(c > 0) {
        if(long f = flow(1,1e9)) total += f;
        else c/=2;
        for (int i = 0; i <= 101; i++) k[i] = 0;
    }
    cout << total << endl;
    return 0;
}
