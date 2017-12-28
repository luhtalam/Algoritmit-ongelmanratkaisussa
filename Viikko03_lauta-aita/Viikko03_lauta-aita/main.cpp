#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
        int n;
        long k;
        cin >> n;
        vector<long> v;
        for (int i = 0; i<n; i++) {
            cin >> k;
            v.push_back(k);
        }
        v.push_back(0);
        priority_queue<pair<int,int>> pq;
        pq.push({0,-1});
        int i = 0;
        long long max = 0, A;
        pair<long,int> p;
        while(i <= n) {
            if(v[i] >= pq.top().first) {
                pq.push({v[i],i});
            } else {
                while(v[i] < pq.top().first) {
                    p = pq.top();
                    while(p.first == pq.top().first) pq.pop();
                    A = p.first*(i-pq.top().second -1);
                    if(A>max) max = A;
                }
                pq.push({v[i],i});
            }
            i++;
        }
        cout << max << "\n";
}
