#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int k[100001];
vector<int> v[100001];

int main() {
    cin.sync_with_stdio(0);
    int n=1,m,a,b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    int M=0, count;
    for (int i = 1; i <= n; i++) {
        if(k[i] == 0) {
            count = 1;
            k[i] = 1;
            q.push(i);
            while (!q.empty()) {
                a = q.front();
                q.pop();
                for (auto u : v[a]) {
                    if (k[u]) continue;
                    k[u] = 1;
                    count++;
                    q.push(u);
                }
            }
            if(M < count) M = count;
        }
    }
    cout << M << endl;
    return 0;
}
