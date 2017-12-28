#include <iostream>
#define M 1000000007;

using namespace std;

int pot(int a, int b) {
    if(b == 0) return 1;
    long u = pot(a, b/2);
    u = (u*u)%M;
    if(b%2 == 1) u = (u*a)%M;
    return (int)u;
}

int main() {
    cin.sync_with_stdio(0);
    int n,a,b;
    cin >>n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << pot(a,b) << endl;
    }
    return 0;
}
