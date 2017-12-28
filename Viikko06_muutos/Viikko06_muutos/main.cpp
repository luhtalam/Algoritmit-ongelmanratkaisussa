#include <iostream>
#include <array>
#include <math.h>

using namespace std;

int N = (1<<18)-1;
int p[2*(1<<18)][3];


array<int,3> summa(int a, int b, int k, int x, int y) {
    if (b < x || a > y)
        return array<int,3> {(int)1e9,(int)-1e9,0};
    if (a <= x && b >= y) {
        return array<int,3>{p[k][0],p[k][1],p[k][2]};
    }
    int d = (y-x+1)/2;
    array<int,3> v = summa(a,b,2*k,x,x+d-1);
    array<int,3> o = summa(a,b,2*k+1,x+d,y);
    int muutos = max(v[2],o[2]);
    muutos = max(muutos, o[1]-v[0]);
    return array<int,3> {min(v[0],o[0]), max(v[1],o[1]), muutos};
}

int main() {
    cin.sync_with_stdio(0);
    int n,q,a,b;
    cin >> n;
    for (int i = 1; i < 2*(1<<5); i++) {
        p[i][0] = 1e9;
        p[i][1] = -1e9;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[N+i][0];
        p[N+i][1] = p[N+i][0];
    }
    for (int i = N; i >= 1; i--) {
        p[i][0] = min(p[2*i][0], p[2*i+1][0]);
        p[i][1] = max(p[2*i][1], p[2*i+1][1]);
        p[i][2] = max(p[2*i][2], p[2*i+1][2]);
        p[i][2] = max(p[i][2], p[2*i+1][1]-p[2*i][0]);
    }
    cin >> q;
    array<int,3> vast;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        a--;
        b--;
        vast = summa(a,b,1,0,N);
        cout << vast[2] << "\n";
    }
    return 0;
}
