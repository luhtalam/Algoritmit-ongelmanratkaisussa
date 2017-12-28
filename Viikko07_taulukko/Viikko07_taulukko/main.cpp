#include <iostream>
#include <math.h>

using namespace std;

int N = 1<<17;
long p[1<<18][4];

int main() {
    cin.sync_with_stdio(0);
    int n,k,a,i;
    cin >> n >> k;
    for (int i = N; i < N+n; i++) {
        cin >> a;
        p[i][0] = a;
        p[i][1] = a;
        p[i][2] = a;
        p[i][3] = a;
    }
    for (int i = N+n; i < (N<<1); i++) {
        p[i][0] = (int) -1e9-1;
        p[i][1] = (int) -1e9-1;
        p[i][2] = (int) -1e9-1;
        p[i][3] = (int) -1e9-1;
    }
    for (int i = N-1; i > 0; i--) {
        p[i][0] = max(p[i<<1][0], p[i<<1][2]+p[(i<<1)+1][0]);
        p[i][1] = max(p[(i<<1)+1][1], p[i<<1][1]+p[(i<<1)+1][2]);
        p[i][2] = p[i<<1][2]+p[(i<<1)+1][2];
        p[i][3] = max(p[i][0], p[i][1]);
        p[i][3] = max(p[i][3], p[i][2]);
        p[i][3] = max(p[i][3], p[i<<1][1] +p[(i<<1)+1][0]);
        p[i][3] = max(p[i][3], p[(i<<1)][3]);
        p[i][3] = max(p[i][3], p[(i<<1)+1][3]);
    }
    for (int j = 0; j<k; j++) {
        cin >> i >> a;
        i+=N-1;
        p[i][0] = a;
        p[i][1] = a;
        p[i][2] = a;
        p[i][3] = a;
        for (int b = (i>>1); b > 0; b = (b>>1)) {
            p[b][0] = max(p[b<<1][0], p[b<<1][2]+p[(b<<1)+1][0]);
            p[b][1] = max(p[(b<<1)+1][1], p[b<<1][1]+p[(b<<1)+1][2]);
            p[b][2] = p[b<<1][2]+p[(b<<1)+1][2];
            p[b][3] = max(p[b][0], p[b][1]);
            p[b][3] = max(p[b][3], p[b][2]);
            p[b][3] = max(p[b][3], p[b<<1][1] +p[(b<<1)+1][0]);
            p[b][3] = max(p[b][3], p[(b<<1)][3]);
            p[b][3] = max(p[b][3], p[(b<<1)+1][3]);
        }
        cout << p[1][3] << endl;
    }
    return 0;
}
