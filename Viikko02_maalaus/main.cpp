#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n, q, k, x, yla, ala, p1,p2;
    set<int> v;
    multiset<int> m;
    cin >> n >> q;
    for (int i = 0; i <= n + 1; i++) {
        v.insert(i);
    }
    for (int i = 0; i < q; i++) {
        cin >> k >> x;
        auto it = v.upper_bound(x);
        yla = *it;
        it--;
        if (k == 1) {
            it--;
            ala = *it;
            v.erase(x);
            m.insert(yla - ala - 1);
            p1 = yla -x-1;
            p2 = x-ala-1;
            if (p1 > 0) m.erase(m.find(p1));
            if (p2) m.erase(m.find(p2));
        } else {
            ala = *it;
            v.insert(x);
            m.erase(m.find(yla - ala - 1));
            p1 = yla -x-1;
            p2 = x-ala-1;
            if (p1 > 0) m.insert(p1);
            if (p2 > 0) m.insert(p2);
        }
        if (m.empty()) {
            cout << "0" << "\n";
        } else {
            it = m.end();
            it--;
            cout << *it << "\n";
        }
    }
}

