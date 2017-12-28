#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n,a; 
    long sml = 1;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if(v[i] <= sml) {
            sml += v[i];
        } else {
            break;
        }
    }
    cout << sml;
}

