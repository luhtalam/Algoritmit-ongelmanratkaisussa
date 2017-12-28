#include <iostream>
#include <math.h>
#include <vector>

#define M 1000000007;

using namespace std;

int n;
int pos = 1;
int p[100001];
int k1[100001];
int s1[100001];
int k2[100001];
int s2[100001];
vector<int> v[100001];

int id1(int x) {
    while (x != k1[x]) x = k1[x];
    return x;
}

int id2(int x) {
    while (x != k2[x]) x = k2[x];
    return x;
}

void liita1(int a, int b) {
    a = id1(a);
    b = id1(b);
    if(a == b) return;
    n--;
    if (s1[b] > s1[a]) swap(a,b);
    s1[a] += s1[b];
    k1[b] = a;
}

void liita2(int a, int b) {
    a = id2(a);
    b = id2(b);
    if(a == b) return;
    if (s2[b] > s2[a]) swap(a,b);
    s2[a] += s2[b];
    k2[b] = a;
}

int main() {
    cin.sync_with_stdio(0);
    int m,a,b;
    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i <= n ; i++) {
        k1[i] = i;
        s1[i] = 1;
        k2[i] = i;
        s2[i] = 1;
        p[i] = (p[i-1]<<1) % M;
    }
    n--;
    for (int i = 0; i < m; i++) {
        if(pos) {
            cin >> a >> b;
            liita1(a,b);
            if(id2(a) == id2(b)) pos= 0;
            if(!v[a].empty()) liita2(b,v[a][0]);
            if(!v[b].empty()) liita2(a,v[b][0]);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(pos){
            cout << p[n]<< endl;
        }else {
            cout << "0" << endl;
        }
    }
    return 0;
}
