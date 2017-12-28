#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n,j;
    int M = 1000000007;
    cin >> n;
    vector<vector<long>> v(n, vector<long>(201,0));
    for (int i = 1; i < 201; i++) {
        v[0][i] = 1;
    }
    for (int i = 0; i < n-1; i++) {
        cin >> j;
        if (j == 0) {
            for (int k = 2; k < 200; k++) {
                v[i+1][k-1] += v[i][k];
                v[i+1][k+1] += v[i][k];
                v[i+1][k-1] %= M;
                v[i+1][k+1] %= M;
            }
            v[i+1][199] += v[i][200];
            v[i+1][2] += v[i][1];
            v[i+1][199] %= M;
            v[i+1][2] %= M;
        } else {
            if(j > 1) {
                v[i+1][j-1] += v[i][j];
                v[i+1][j+1] += v[i][j];
                v[i+1][j-1] %= M;
                v[i+1][j+1] %= M;
            } else {
                v[i+1][j+1] += v[i][j];
                v[i+1][j+1] %= M;
            }
        }
    }
    cin >> j;
    n--;
    if(j == 0) {
        long sum = 0;
        for (int i = 1; i < 201; i++) {
            sum += v[n][i];
            sum %= M;
        }
        cout << sum << "\n";
    } else {
        cout << v[n][j] << "\n";
    }
}
