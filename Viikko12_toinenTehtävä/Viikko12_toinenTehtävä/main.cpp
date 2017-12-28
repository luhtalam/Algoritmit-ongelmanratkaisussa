#include <iostream>
#define M 1000000007;

using namespace std;
long m[4] = {1,1,1,0};

void mul(long f[4], long g[4]) {
    long a,b,c,d;
    a = f[0]*g[0]+f[1]*g[2];
    a %= M;
    b = f[0]*g[1]+f[1]*g[3];
    b %= M;
    c = f[2]*g[0]+f[3]*g[2];
    c %= M;
    d = f[2]*g[1]+f[3]*g[3];
    d %= M;
    f[0] = a; f[1] = b; f[2] = c; f[3] = d;
}

void pow(long f[4], long n) {
    if(n == 0 || n == 1) return;
    pow(f,n/2);
    mul(f,f);
    if(n%2) {
        mul(f,m);
    }
}

int main() {
    cin.sync_with_stdio(0);
    long n;
    cin >> n;
    long v[4] = {1,1,1,0};
    pow(v,n+1);
    cout << v[0]-1 << endl;
    return 0;
}
