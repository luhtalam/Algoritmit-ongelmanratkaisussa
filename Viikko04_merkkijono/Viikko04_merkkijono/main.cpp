#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n,m,a,b;
    cin >> n >> m;
    vector<vector<pair<int, long>>> v(m+1);
    cin >> b;
    v[0].push_back({b,0});
    for (int i = 1; i <= m; i++) {
        cin >> a;
        v[0].push_back({a,0});
        v[1].push_back({a+b,a+b});
        b = a;
    }
    long sum;
    long k;
    for (int i = 2; i <= m; i++) {
        for (int l = 0; l <= m-i; l++) {
            k = 1000000000000;
            for (int j = 1; j <= i; j++) {
                sum = v[j-1][l].second + v[i-j][l+j].second;
                k = min(k,sum);
            }
            sum = v[0][l].first+v[i-1][l+1].first;
            v[i].push_back({sum,sum +k});
        }
    }
    cout << v[m][0].second << "\n";
}
