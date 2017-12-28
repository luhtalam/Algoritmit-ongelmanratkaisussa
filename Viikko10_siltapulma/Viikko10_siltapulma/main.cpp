#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

vector<int> v[100001];
pair<int,int> s[100001];
int p[100001];
int k[100001];

int main() {
    cin.sync_with_stdio(0);
    int n,m,a,b,c;
    cin >> n >> m;
    for (int i = 1; i <=m; i++) {
        cin >> a >> b;
        v[a].push_back(i);
        v[b].push_back(i);
        s[i] = {a,b};
        p[a] = 1-p[a];
        p[b] = 1-p[b];
    }
    for (int i = 1; i <=n; i++) {
        if(p[i]){
            cout << "QAQ\n";
            return 0;
        }
    }
    stack<int> path;
    vector<int> circuit;
    c = v[1].back();
    v[1].pop_back();
    k[c] = 1;
    a = s[c].first;
    if(a == 1) a = s[c].second;
    path.push(c);
    while(!path.empty()) {
        if(v[a].size()) {
            c = v[a].back();
            if(k[c]) {
                v[a].pop_back();
            } else {
                k[c] = 1;
                v[a].pop_back();
                b = s[c].first;
                if(a == b) b = s[c].second;
                a = b;
                path.push(c);
            }
        } else {
            c = path.top();
            path.pop();
            b = s[c].first;
            if(a == b) b = s[c].second;
            a = b;
            circuit.push_back(c);
        }
    }
    for(auto u: circuit) {
        cout << u << endl;
    }
    return 0;
}
