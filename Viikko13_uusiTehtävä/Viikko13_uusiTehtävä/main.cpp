#include <iostream>
#define M 1000000007;

using namespace std;

long pot(int a, int b) {
    if(b == 0) return 1;
    long u = pot(a, b/2);
    u = (u*u)%M;
    if(b%2 == 1) u = (u*a)%M;
    return u;
}

int main() {
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    long a = pot(13,n);
    long b = a+1;
    long ans = a*b;
    ans %= M;
    ans*=500000004;
    ans %= M;
    500000004;
    cout << ans << endl;
    return 0;
}
