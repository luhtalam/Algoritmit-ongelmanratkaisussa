#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int k;
    long double p[7];
    cin >> k;
    for (int i = 1; i <7; i++) cin >> p[i];
    long double ans = 0;
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            for (int a = 1; a < 7; a++) {
                for (int b = 1; b < 7; b++) {
                    if((i+j)-(a+b)>k) ans += p[i]*p[j]*p[a]*p[b];
                }
            }
        }
    }
    cout.precision(6);
    cout << ans << endl;
    return 0;
}
