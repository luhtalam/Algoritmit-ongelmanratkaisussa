#include <iostream>

using namespace std;

int N = (1<<17)-1;
int p[2*(1<<17)];
int jono[100001];

void lisaa(int k, int x) {
    k += N;
    p[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        p[k] = p[2*k]+p[2*k+1];
    }
}

int summa(int a, int b) {
    a += N; b += N;
    int s = 0;
    while (a <= b) {
        if (a%2 == 1) s += p[a++];
        if (b%2 == 0) s += p[b--];
        a /= 2; b /= 2;
    }
    return s; }

int main() {
    cin.sync_with_stdio(0);
    int q,t,x,i;
    cin >> q;
    int e = 1;
    int v = 1;
    for (int j = 0; j < q; j++) {
        cin >> t;
        if(t == 1 ) {
            cin >> x;
            jono[v]= x;
            lisaa(v,1);
            v++;
            continue;
        } else if(t == 2){
            cin >> x;
            if(x == 1) {
                cout << jono[e] << "\n";
                continue;
            }
            i = e;
            for (int j = v-1; j > 0; j /=2) {
                while(i+j < v && summa(e,i+j) < x) i +=j;
            }
            cout << jono[i+1] << "\n";
        } else if(t ==3) {
            lisaa(e, -1);
            while(p[e+N] == 0 && e < v) e++;
        } else {
            cin >> x;
            if(x == 1) {
                lisaa(e, -1);
                while(p[e+N] == 0 && e < v) e++;
                continue;
            }
            i = e;
            for (int j = v-1; j > 0; j /=2) {
                while(i+j < v && summa(e,i+j) < x) i +=j;
            }
            lisaa(i+1, -1);
        }
    }
}
