#include <iostream>

using namespace std;

int N = (1<<17)-1;
long p[2*(1<<17)];
int angry = 0;


void init() {
    for (int i = (N+1)/2; i > 0; i /=2) {
        for (int j = 0; j < i; j++) {
            p[i+j] = p[2*(i+j)] + p[2*(i+j)+1];
        }
    }
}

void update(int a, int x) {
    a += N;
    p[a] = x;
    while(a>1) {
        a/=2;
        p[a] = p[2*a]+p[2*a+1];
    }
}

long sum(int a, int b) {
    a += N; b += N;
    long s = 0;
    while (a <= b) {
        if (a%2 == 1) s += p[a++];
        if (b%2 == 0) s += p[b--];
        a /= 2; b /= 2;
    }
    return s; }

void isAngry(int k, int x) {
    int a = k;
    for (int i = N+1; i >= 1; i /=2) {
        while(a+i < N+1 && sum(k,a+i)<= x) a+= i;
    }
    if(sum(k,a) != x) angry++;
}

int main() {
    cin.sync_with_stdio(0);
    int n,q,t,k,x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i+N];
    }
    init();
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> t >> k >> x;
        if(t == 1) {
            isAngry(k,x);
        } else {
            update(k, x);
        }
    }
    cout << angry << "\n";
    return 0;
}
