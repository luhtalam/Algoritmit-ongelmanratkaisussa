#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100001];
int k[100001];
int d[100001];

int main() {
    cin.sync_with_stdio(0);
    int n,a,b,D= 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        a =q.front(); q.pop();
        for(auto b : v[a]) {
            if(k[b]) continue;
            k[b] = 1;
            q.push(b);
        }
    }
    for (int i = 0; i <= n; i++) {
        k[i] = 0;
    }
    q.push(a);
    while(!q.empty()) {
        a =q.front(); q.pop();
        for(auto b : v[a]) {
            if(k[b]) continue;
            k[b] = 1;
            d[b] = d[a] +1;
            D = d[b];
            q.push(b);
        }
    }
    cout << D << endl;
    return 0;
}
