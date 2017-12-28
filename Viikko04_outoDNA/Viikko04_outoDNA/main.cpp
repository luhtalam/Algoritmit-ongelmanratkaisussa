#include <iostream>

using namespace std;

const int M = 1000000007;
long d[10000][2][2][2][2];

int main() {
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    n--;
    d[0][0][1][1][1] = 1;
    d[0][1][0][1][1] = 1;
    d[0][1][1][0][1] = 1;
    d[0][1][1][1][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int a = 0; a < 2; a++) {
            for (int c = 0; c < 2; c++) {
                for (int g = 0; g < 2; g++) {
                    for (int t = 0; t < 2; t++) {
                        d[i+1][a][c][g][t] = d[i][1-a][c][g][t] + d[i][a][1-c][g][t] + d[i][a][c][1-g][t] + d[i][a][c][g][1-t];
                        d[i+1][a][c][g][t] %= M;
                    }
                }
            }
        }
    }
    cout << d[n][1][1][1][1] << "\n";
}
