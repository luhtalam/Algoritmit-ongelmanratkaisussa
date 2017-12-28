#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> v[50001];
int e[50001];
int k[50001];

int main() {
    cin.sync_with_stdio(0);
    int n, m,a,b,t;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        v[a].push_back({b,t});
        v[b].push_back({a,t});
    }
    for (int i = 2; i <= n; i++) {
        e[i] = 1e9;
    }
    e[1] = 0;
    priority_queue<pair<int,int>> q;
    q.push({0,1});
    while (!q.empty()) {
        a = q.top().second; q.pop();
        if(a == n) break;
        if (k[a]) continue;
        k[a] = 1;
        for (auto b : v[a]) {
            if(e[a]+b.second < e[b.first]) {
                e[b.first] = e[a]+b.second;
                q.push({-e[b.first],b.first});
            }
        }
    }
    cout << e[n] << endl;
    return 0;
}
