#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> v[100001];
int k[100001];

int main() {
    cin.sync_with_stdio(0);
    int n, m, a,b,c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    priority_queue<pair<int,int>> q;
    for (auto b: v[1]) {
        q.push({b.second,b.first});
    }
    k[1] = 1;
    int M = 1e9,count = 1;
    pair<int,int> p;
    while(!q.empty()) {
        p = q.top();q.pop();
        if(k[p.second]) continue;
        if(M > p.first) M = p.first;
        k[p.second] = 1;
        for (auto b: v[p.second]) {
            q.push({b.second,b.first});
        }
        count++;
        if(count == n) break;
    }
    cout << M << endl;
    return 0;
}
