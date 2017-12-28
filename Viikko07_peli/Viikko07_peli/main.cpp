#include <iostream>
#include <vector>
#include <algorithm>

#define F first
#define S second

using namespace std;

int N = (1<<18);
long p[2*(1<<18)];


long maksimi(int a, int b) {
    if(a == b) return 0;
    a += N; b+= N;
    long t = p[a];
    while (a <= b) {
        if (a%2 == 1) t = max(t, p[a++]);
        if (b%2 == 0) t = max(t, p[b--]);
        a = (a >> 1); b = (b >> 1);
    }
    return t;
}

void aseta(int k, long x) {
    k += N;
    p[k] = x;
    for (k /= 2; k > 0; k /= 2) {
        p[k] = max(p[(k << 1)], p[(k << 1)+1]);
    }
}

int main() {
    cin.sync_with_stdio(0);
    int n,x,y,c;
    cin >> n;
    vector<pair<pair<int,int>,int>> v(n);
    vector<pair<int,int>> vy(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> c;
        v[i] = {{x,y},c};
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++) {
        vy[i] = {v[i].F.S, i};
    }
    sort(vy.begin(), vy.end());
    int j;
    long M;
    for (int i = 0; i < n; i++) {
        j = vy[i].S;
        M = maksimi(0,j);
        aseta(j,M + v[j].S);
    }
    cout << p[1] << endl;
    return 0;
}
