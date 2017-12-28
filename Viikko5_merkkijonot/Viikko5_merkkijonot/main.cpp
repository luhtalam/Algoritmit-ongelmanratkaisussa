#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s;
vector<string> v;

int main() { //permutaatiot tulevat suoraan vain kerran ja järjestyksessä
    cin.sync_with_stdio(0);
    cin >> s;
    int n = s.length();
    sort(s.begin(), s.end());
    do {
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << v.size() << "\n";
    n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }
}
