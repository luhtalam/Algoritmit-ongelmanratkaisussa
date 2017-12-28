#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    int a, l;
    for (int i = 0; i < n; i++) {
        cin >> a >> l;
        v.push_back({l, a});
    }
    multiset<int> s;
    int numb = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < k; i++) s.insert(0);
    for (int i = 0; i < n; i++) {
        auto a = s.upper_bound(v[i].second);
        if(a == s.begin()) continue;
        a--;
        s.erase(a);
        s.insert(v[i].first);
        numb++;
    }
    cout << numb << "\n";
}

