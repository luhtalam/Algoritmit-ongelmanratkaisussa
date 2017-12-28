#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n;
long e = 1e18;


void find(long a, long b, long c, int i) {
    if(i == n) {
        long mx = max(a,b);
        mx = max(mx,c);
        long mn = min(a,b);
        mn = min(mn,c);
        e = min(e, mx-mn);
    }else {
        find(a+v[i],b,c,i+1);
        find(a,b+v[i],c,i+1);
        find(a,b,c+v[i],i+1);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    find(0,0,0,0);
    cout << e << "\n";
}
