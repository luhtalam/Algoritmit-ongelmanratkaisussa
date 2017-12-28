#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

P t[2002];

bool mySort(P c1, P c2) {
    return c1.X == c2.X ? c1.Y < c2.Y : c1.X < c2.X;
}

int main() {
    cin.sync_with_stdio(0);
    C n,x,y;
    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        cin >> x >> y;
        t[i] = {x,y};
    }
    C r1,r2,r3,r4;
    P p1,p2,s1,s2,a,b;
    for (int i = 0; i < 2*n; i+= 2) {
        p1 = t[i]; p2 = t[i+1];
        for (int j = i+2; j < 2*n; j+=2) {
            s1 = t[j]; s2 = t[j+1];
            if(s1 == p1 || s1 == p2 || s2 == p1 || s2 == p2) {
                cout << "QAQ\n";
                return 0;
            }
            a = p1-s1; b = p1-s2;
            r1 = (conj(a)*b).Y;
            a = p2-s1; b = p2-s2;
            r2 = (conj(a)*b).Y;
            a = s1-p1; b = s1-p2;
            r3 = (conj(a)*b).Y;
            a = s2-p1; b = s2-p2;
            r4 = (conj(a)*b).Y;
            if(r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0) {
                vector<P> v = {s1,s2,p1,p2};
                sort(v.begin(),v.end(), mySort);
                for (int i = 0; i < 4; i++) {
                    if(v[i] == s1) x = i;
                    if(v[i] == s2) y = i;
                }
                if(abs(x-y) != 1) {
                    cout << "QAQ\n";
                    return 0;
                }
            }
            if(((r1 <0 && r2 > 0) || (r1 > 0 && r2 <0)) && ((r3 <0 && r4 > 0) || (r3 > 0 && r4 <0))) {
                cout << "QAQ\n";
                return 0;
            }
        }
    }
    cout << "10-4\n";
    return 0;
}
