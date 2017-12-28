#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 100000;
vector<pair<int,int>> v[200001];
int k[200001];
long long e[200001];

int main() {
    cin.sync_with_stdio(0);
    int n, m,a,b,c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[a].push_back({b+N, c/2});
        v[a+N].push_back({b+N,c});
    }
    for (int i = 2; i < 200001; i++) {
        e[i] = 1e18;
    }
    priority_queue<pair<long,int>> q;
    e[1] = 0;
    q.push({0,1});
    while(!q.empty()) {
        a = q.top().second; q.pop();
        if(k[a]) continue;
        k[a] = 1;
        for (auto b: v[a]) {
            if(e[a]+ b.second < e[b.first]) {
                e[b.first] = e[a]+ b.second;
                q.push({-e[b.first], b.first});
            }
        }
    }
    cout << e[n+N] << endl;
    return 0;
}
