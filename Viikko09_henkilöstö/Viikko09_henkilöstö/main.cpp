#include <iostream>
#include <math.h>

using namespace std;

int dp[18][200001];

int main() {
    cin.sync_with_stdio(0);
    int n,q,x,k;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> dp[0][i];
    }
    for (int j = 1; j < 18; j++) {
        for (int i = 2; i <= n; i++) {
            dp[j][i] = dp[j-1][dp[j-1][i]];
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> k;
        for (int j = 17; j >= 0; j--) {
            while (k >= (1<<j)) {
                x = dp[j][x];
                k -= (1<<j);
            }
        }
        if(x) cout << x << endl;
        else cout << "QAQ" << endl;
    }
    return 0;
}
