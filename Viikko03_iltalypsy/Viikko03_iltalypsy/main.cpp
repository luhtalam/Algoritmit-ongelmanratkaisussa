#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n, m, x, k = 1;
    cin >> n >> m;
    unordered_set<int> s;
    for (int i = 0; i < m; i++) {
        cin >> x;
        s.insert(x);
        while(s.find(k) != s.end()) k++;
        cout << k << " ";
    }
}
