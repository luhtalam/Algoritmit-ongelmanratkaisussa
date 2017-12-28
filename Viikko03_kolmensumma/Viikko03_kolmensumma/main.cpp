#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n,x,a,h;
    cin >> n >> x;
    vector<int> v;
    for (int i = 0; i <n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int i, j;
    bool f = true;
    int k = 0;
    while (f) {
        h = x - v[k];
        i = k+1;
        j = n-1;
        while(i < j) {
            while(v[i] + v[j] > h) j--;
            if(v[i] + v[j] == h) {
                cout << v[k] << " " << v[i] << " " << v[j];
                f = false;
                return 0;
            }
            i++;
        }
        k++;
    }
}
