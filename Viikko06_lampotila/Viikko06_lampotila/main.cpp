#include <iostream>
#include <math.h>

using namespace std;

int p[100000];
int A[100000][18];
int B[100000][18];

int main() {
    cin.sync_with_stdio(0);
    int n,q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        A[i][0] = p[i];
        B[i][0] = p[i];
    }
    int l;
    for (int i = 1; i < 18; i++) {
        l = pow(2,i-1);
        for (int j = 1; j <= n; j++) {
            if(j+l > n) {
                A[j][i] = A[j][i-1];
                B[j][i] = B[j][i-1];
            }else {
                A[j][i] = min(A[j][i-1], A[j+ l][i-1]);
                B[j][i] = max(B[j][i-1], B[j + l][i-1]);
            }
        }
    }
    cin >> q;
    int a, b,k;
    int low, high;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        k = log2(b-a+1);
        l = pow(2,k);
        low = min(A[a][k], A[b-l+1][k]);
        high = max(B[a][k], B[b-l+1][k]);
        cout << low << " " << high << "\n";
    }
    return 0;
}
