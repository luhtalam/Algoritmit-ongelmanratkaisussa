#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n,a,b;
vector<int> v;

long long countWays(int k) {
    if(k == 0) return 0;
    map<int,int> m;
    long long sum = 0;
    long long i = 0, j = 1, c = 1, oldj = 0;
    m[v[i]] = 1;
    while(true) {
        while(j < n && c < k) {
            if(m.count(v[j])) {
                m[v[j]]++;
                j++;
            } else {
                m[v[j]] = 1;
                c++;
                j++;
            }
        }
        while(j < n && m.count(v[j])) {
            m[v[j]]++;
            j++;
        }
        sum += ((j-i)*(j-i+1))/2;
        if (oldj > i) sum -= ((oldj-i)*(oldj-i+1))/2;
        oldj = j;
        while(i < n && c == k) {
            if(m[v[i]] == 1) {
                m.erase(v[i]);
                c--;
                i++;
            } else {
                m[v[i]]--;
                i++;
            }
        }
        if (j >= n) {
            break;
        }
    }
    return sum;
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> a >> b;
    int c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        v.push_back(c);
    }
    cout << countWays(b) - countWays(a-1) << "\n";
}
