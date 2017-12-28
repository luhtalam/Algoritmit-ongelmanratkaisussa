#include <iostream>

using namespace std;

#define M 1000000007

int p[1001][1001];
char a[1000][1000];

int main() {
    cin.sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    p[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] == '*') continue;
            p[i+1][j] += p[i][j];
            p[i+1][j] %= M;
            p[i][j+1] += p[i][j];
            p[i][j+1] %= M;
        }
    }
    cout << p[n-1][m-1] << "\n";
    return 0;
}
