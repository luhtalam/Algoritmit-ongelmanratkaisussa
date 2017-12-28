#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    cin.sync_with_stdio(0);
    int n,b,a,p;
    cin >> n;
    vector<pair<pair<int,int>,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> p;
        v[i] = {{b,a},p};
    }
    sort(v.begin(), v.end());
    vector<long> dp(n+1);
    dp[0] = 0;
    int x,s;
    for (int i = 0; i < n; i++) {
        s = v[i].first.second;
        x = -1;
        for (int b = n; b > 0; b /=2) {
            while(x+b < n && v[x+b].first.first<s) x +=b;
        }
        x++;
        dp[i+1] = max(dp[i], dp[x]+v[i].second);
    }
    cout << dp[n] << endl;;
    return 0;
}
