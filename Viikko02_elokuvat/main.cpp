
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    cin.sync_with_stdio(0);
    int n,a,b;
    int numb = 0, e = 0;
    vector<pair<int,int>> v;
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++) {
        if(v[i].second >= e) {
            numb++;
            e = v[i].first;
        }
    }
    cout << numb;
}

