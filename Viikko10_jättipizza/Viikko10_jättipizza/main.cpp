#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> v[100001];
vector<int> r[100001];
vector<int> list;
int k[100001];
int c[100001];
int inc[100001];
int comp = 0;

void haku(int s) {
    k[s] = 1;
    for(auto u: v[s]) {
        if(!k[u]) haku(u);
    }
    list.push_back(s);
}

void haku2(int s) {
    c[s] = comp;
    for(auto u: r[s]) {
        if(!c[u]) haku2(u);
    }
}

int main() {
    cin.sync_with_stdio(0);
    int n,m,a,b;
    char ca,cb;
    cin >> n >> m;
    for (int i = 0; i < m; i++) { // asetetaan neg(a) -> b ja neg(b) -> a
        cin >> ca >> a >> cb >> b;
        if(ca == '-') a *= -1;
        if(cb == '-') b *= -1;
        v[n-a].push_back(n+b);
        r[n+b].push_back(n-a);
        v[n-b].push_back(n+a);
        r[n+a].push_back(n-b);
    }
    for (int i = 0; i <= 2*n; i++) { //syvyyshaun mukainen käsittelyjärjestys
        if(i == n) continue;
        if(!k[i]) haku(i);
    }
    for (auto it = --list.end(); it >= list.begin(); it--) { //muodostetaan komponentit
        if(!c[*it]) {comp++; haku2(*it);}
    }
    for (int i = 1; i <= n; i++) { //tarkistetaan sijaitseeko muuttuja ja sen negaatio samassa komponentissa
        if(c[n-i] == c[n+i]) {
            cout << "QAQ\n"; // jos sijaitsee lausekkeelle ei löydy vastausta
            return 0;
        }
    }
    comp = 0;
    for (auto u : list) { //käsitellään komponenttiverkko käänteisessä järjestyksessä
        a = abs(u-n);
        if(!inc[a]){
            inc[a] = u-n;
            comp++;
        }
        if(comp == n) break;
    }
    for (int i = 1; i <= n; i++) {
        if(inc[i] > 0) cout << '+' << " ";
        else cout << '-' << " ";
    }
    return 0;
}
