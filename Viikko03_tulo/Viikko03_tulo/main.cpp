#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int n, q;
vector<long> v(1000001,0);
vector<long> sum(1000001,0);
vector<long> numbers;
vector<long long> products(1000001,0);
unordered_set<long> s;

int main() {
    cin.sync_with_stdio(0);
    long a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v[a]++;
        if(!s.count(a)) {
            s.insert(a);
            numbers.push_back(a);
        }
    }
    sort(numbers.begin(),numbers.end());
    sum[1e6 +1] =v[1e6 +1];
    for (int i = 1e6; i > -1; i--) {
        sum[i] = v[i] + sum[i+1];
    }
    long long prod;
    for (int i = 0; i < numbers.size(); i++) {
        if(v[numbers[i]] > 1 ) {
            if(numbers[i] < 1000) {
                prod = numbers[i]*numbers[i];
                products[prod] += v[numbers[i]]*(v[numbers[i]]-1);
            } else {
                products[1e6] += v[numbers[i]]*(v[numbers[i]]-1);
            }
        }
        for (int j = i+1; j < numbers.size(); j++) {
            prod = numbers[i]*numbers[j];
            if(prod < 1e6) {
                products[prod] += 2* v[numbers[i]]*v[numbers[j]];
            } else {
                products[1e6] += 2* v[numbers[i]]*sum[numbers[j]];
                break;
            }
        }
    }
    for (int i = 1e6; i > -1; i--) {
        products[i] += products[i+1];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a;
        cout << products[a] << "\n";
    }
}
