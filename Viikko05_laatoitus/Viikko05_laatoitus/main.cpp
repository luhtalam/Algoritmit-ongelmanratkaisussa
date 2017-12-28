#include <iostream>
#include <math.h>

using namespace std;

long double p = 3.141592653589793238L;

int main() {
    cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    if(n%2==1 && m%2==1){
        cout << "0\n";
        return 0;
    }
    long double ans = 1.0L;
    long double cosA;
    long double cosB;
    for (int a = 1; a <= n/2; a++) {
        for (int b = 1; b <= m/2; b++) {
            cosA = cosl(p*a/(n+1));
            cosB = cosl(p*b/(m+1));
            cosA = powl(cosA, 2.0L);
            cosB = powl(cosB, 2.0L);
            ans *= 4.0L*(cosA+cosB);
        }
    }
    cout << (long)ans << "\n";
}
