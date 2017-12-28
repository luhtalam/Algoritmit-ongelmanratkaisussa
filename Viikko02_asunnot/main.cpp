#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n, m, c, d;
    cin >> n >> m;
    vector<pair<int, int>> a;
    vector<pair<int, int>> h;
    for (int i = 0; i < n; i++) {
        cin >> c >> d;
        h.push_back({c, d});
    }
    for (int i = 0; i < m; i++) {
        cin >> c >> d;
        a.push_back({c, d});
    }
    sort(a.begin(), a.end());
    sort(h.begin(), h.end());
    multiset<int> k;
    int x = 0;
    int i = 0;
    int j = 0;
    while(i < n) {
        while(j < m && a[j].first <= h[i].first) {
            k.insert(a[j].second);
            j++;
        }
        auto it = k.lower_bound(h[i].second);
        if(it != k.end()) {
            x++;
            k.erase(it);
        }
        i++;
    }
    cout << x;
}

