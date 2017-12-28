#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int A[41];
unordered_map<int, int> SA;

int main() {
    cin.sync_with_stdio(0);
    int n,x,p;
    cin >> n >> x;
    p = n/2;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    long sum;
    for (int i = 0; i < (1 << p); i++) {
        sum = 0;
        for (int j = 0; j<p; j++) {
            if(i&(1<< j)) sum+= A[j];
        }
        if(sum > x) continue;
        SA[sum]++;
    }
    long c = 0;
    for (int i = 0; i < (1 << (n-p)); i++) {
        sum = 0;
        for (int j = 0; j<n-p; j++) {
            if(i&(1<< j)) sum+= A[p+j];
        }
        if(x-sum >= 0) c += SA[(x-sum)];
    }
    cout << c << "\n";
}
