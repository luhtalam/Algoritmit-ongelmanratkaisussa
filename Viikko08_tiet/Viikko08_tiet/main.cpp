#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v[100001];
int k1[100001];
int k2[100001];
int k3[100001];
long e1[100001];
long e2[100001];
long e3[100001];

int main() {
    cin.sync_with_stdio(0);
    int n,m,a,b,c,x,y,z;
    cin >> n >> m;
    cin >> x >> y >> z;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for (int i = 1; i <= n; i++) {
        e1[i] = 1e18;
        e2[i] = 1e18;
        e3[i] = 1e18;
    }
    priority_queue<pair<long,int>> q1;
    priority_queue<pair<long,int>> q2;
    priority_queue<pair<long,int>> q3;
    q1.push({0,x});
    e1[x] = 0;
    q2.push({0,y});
    e2[y] = 0;
    q3.push({0,z});
    e3[z] = 0;
    while(!q1.empty()) {
        a = q1.top().second; q1.pop();
        if(k1[a]) continue;
        k1[a] = 1;
        for (auto b: v[a]) {
            if(e1[a]+b.second < e1[b.first]) {
                e1[b.first] = e1[a]+b.second;
                q1.push({-e1[b.first],b.first});
            }
        }
    }
    while(!q2.empty()) {
        a = q2.top().second; q2.pop();
        if(k2[a]) continue;
        k2[a] = 1;
        for (auto b: v[a]) {
            if(e2[a]+b.second < e2[b.first]) {
                e2[b.first] = e2[a]+b.second;
                q2.push({-e2[b.first],b.first});
            }
        }
    }
    while(!q3.empty()) {
        a = q3.top().second; q3.pop();
        if(k3[a]) continue;
        k3[a] = 1;
        for (auto b: v[a]) {
            if(e3[a]+b.second < e3[b.first]) {
                e3[b.first] = e3[a]+b.second;
                q3.push({-e3[b.first],b.first});
            }
        }
    }
    long M = 1e18;
    long s;
    for (int i = 1; i <= n; i++) {
        s =e1[i]+e2[i]+e3[i];
        M = min(M, s);
    }
    cout << M << endl;
    return 0;
}
