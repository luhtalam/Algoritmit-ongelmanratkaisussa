#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<long long> v;

bool ok(int m) {
    if (m < 2) return true;
    if (m > n / k) return false;
    vector<long long> h;
    vector<int> h1;
    int i = 0;
    for (i = 0; i < m; i++) {
        h.push_back(v[i]);
        h1.push_back(1);
    }
    int j = 0;
    while (i < n) {
        if ((v[i]*2) <= h[j]) {
            h[j] = v[i];
            h1[j]++;
            i++;
            j++;
            if (j == m) j = 0;
        } else {
            i++;
        }
    }
    return h1[m-1] >= k;
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> k;
    long a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.rbegin(), v.rend());
    int x = 0;
    for (int b = n/k ; b >= 1; b /= 2) {
        while (ok(x + b)) {
            x += b;
        }
    }
    cout << x;
}

