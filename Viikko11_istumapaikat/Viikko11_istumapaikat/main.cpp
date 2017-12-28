#include <iostream>
#include <vector>

using namespace std;

int v[102][102];
vector<int> vl[102];
int k[102];
vector<int> table[25];
char t[102];

int flow(int s,int n) {
    k[s] = 1;
    if(s == n)return 1;
    for (auto i: vl[s]) {
        if(!k[i] && v[s][i] > 0) {
            if(flow(i,n)){
                v[s][i] -= 1;
                v[i][s] += 1;
                return 1;
            }
        }
    }
    return 0;
}

void find(int s,int m) {
    table[m].push_back(s);
    k[s] = 1;
    for(auto u: vl[s]) {
        if(u == 0 || u == 101) continue;
        if(t[s] == 'T') {
            if(!v[s][u]) {
                v[s][u] = 1;
                find(u,m);
            }
        } else {
            if(!v[u][s]) {
                v[u][s] = 1;
                find(u,m);
            }
        }
    }
}

int main() {
    int n, m,a,b, g=0, p=0;
    char c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        if(c == 'T') {
            g++;
            v[0][i] = 2;
            vl[0].push_back(i);
            vl[i].push_back(0);
        } else {
            p++;
            v[i][101] = 2;
            vl[i].push_back(101);
            vl[101].push_back(i);
        }
        t[i] = c;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if(t[a] == 'P') swap(a,b);
        if(t[a] != t[b])  {
            v[a][b] = 1;
            vl[a].push_back(b);
            vl[b].push_back(a);
        }
    }
    m = 0;
    while(flow(0,101)) {
        m++;
        for (int i = 0; i <= 101; i++) k[i] = 0;
    }
    if(m < 2*g) {
        cout << "QAQ\n";
        return 0;
    }
    m = 0;
    for(auto s: vl[0]) {
        if(!k[s]) {
            find(s,m);
            table[m].pop_back();
            m++;
        }
    }
    cout << m << endl;
    for(int i = 0; i < m; i++) {
        cout << table[i].size() << " ";
        for(auto u: table[i]) {
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}
