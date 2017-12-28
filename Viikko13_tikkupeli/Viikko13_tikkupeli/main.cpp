#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n,a=0,b;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> b;
        a ^=b;
        v[i] = a;
    }
    unordered_map<int, int> s;
    s[0] = 1;
    long c = 0;
    for(auto u: v) {
        if(s[u]) c += s[u];
        s[u]++;
    }
    cout << c << endl;
    return 0;
}
