#include <iostream>
#include <vector>
#include <math.h>

#define M 1000000007

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<long> v(n+1);
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i <= m; i++) {
        v[i] = 2*v[i-1] % M;
    }
    for (int i = m+1; i <=n; i++) {
        v[i] = (2*v[i-1] -v[i-m-1] +M) % M;
    }
    cout << v[n] << endl;
    return 0;
}
