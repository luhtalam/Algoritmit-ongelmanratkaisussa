#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100001];
int c[100001];
int k[100001];
priority_queue<int> q;
vector<int> list;

void haku(int s) {
    k[s] = 1;
    for (auto u: v[s]) {
        c[u]++;
        if(!k[u]) haku(u);
    }
}


int main() {
    cin.sync_with_stdio(0);
    int n,m,a,b;
    cin >> n >> m;
    for (int i = 0; i <m; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if(k[i] != 2)  {
            q.push(i);
            haku(i);
            while(!q.empty()) {
                a = q.top();
                q.pop();
                k[a] = 2;
                list.push_back(a);
                for (auto u: v[a]) {
                    c[u]--;
                    if(!c[u] && k[u] != 2) q.push(u);
                }
            }
            while(!list.empty()) {
                a = list.back();
                cout << a << " ";
                list.pop_back();
            }
        }
    }
    return 0;
}
