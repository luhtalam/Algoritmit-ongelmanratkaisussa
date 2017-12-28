#include <iostream>
#include <vector>

using namespace std;

int sum = 0;
int n;
vector<string> v;

bool canAdd(vector<int> numbers,int i) {
    if(numbers.empty()) return 1;
    for (int a = 0; a < numbers.size(); a++) {
        if(v[numbers[a]][i] == '0') return 0;
    }
    return 1;
}

void find(vector<int> numbers, int i) {
    if(i >= n) return;
    find(numbers,i+1);
    if(canAdd(numbers,i)) {
        sum++;
        numbers.push_back(i);
        find(numbers, i+1);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> vec;
    find(vec, 0);
    cout << sum<<"\n";
}
