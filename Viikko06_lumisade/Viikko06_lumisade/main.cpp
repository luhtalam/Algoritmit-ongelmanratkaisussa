#include <iostream>

using namespace std;

int N = 131071;
long seg[262144];

void update(int a, int b) {
    a += N; b += N;
    while(a>1) {
        a/=2;
        b/=2;
        seg[a] = seg[2*a]+seg[2*a+1];
        seg[b] = seg[2*b]+seg[2*b+1];
    }
}

long sum(int a, int b) {
    a += N; b += N;
    long s = 0;
    while (a <= b) {
        if (a%2 == 1) s += seg[a++];
        if (b%2 == 0) s += seg[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    cin.sync_with_stdio(0);
    int n,q,t,a,b,s,x;
    cin >> n >> q;
    for (int i = 0; i<q; i++) {
        cin >> t;
        if(t == 1) {
            cin >> a >> b >> s;
            seg[a+N] += s;
            seg[b+N+1] -= s;
            update(a,b+1);
        } else {
            cin >> x;
            cout << sum(1,x) << "\n";
        }
    }
}
