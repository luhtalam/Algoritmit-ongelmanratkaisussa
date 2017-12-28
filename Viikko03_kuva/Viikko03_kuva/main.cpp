#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n;
long long sum;
vector<vector<int>> v;
vector<vector<pair<int,int>>> minMax;
deque<int> minD;
deque<int> maxD;

void addMin(int a) {
    while(!minD.empty() && minD.back() > a) minD.pop_back();
    minD.push_back(a);
}

void addMax(int a) {
    while(!maxD.empty() && maxD.back() < a) maxD.pop_back();
    maxD.push_back(a);
}



int main() {
    cin.sync_with_stdio(0);
    int p;
    cin >> n;
    v.resize(n);
    minMax.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <n; j++) {
            cin >> p;
            v[i].push_back(p);
        }
    }
    cout << "0\n";
    long long sum;
    for (int k = 2; k <= n; k++) {
        sum = 0;
        minD.resize(k);
        maxD.resize(k);
        for (int j = 0; j <n; j++) {
            minD.clear();
            maxD.clear();
            minMax[j].resize(n);
            for (int i = 0; i < n; i++) {
                if(i < k) {
                    addMin(v[j][i]);
                    addMax(v[j][i]);
                }else {
                    minMax[j][i-k] = {minD.front(), maxD.front()};
//                    cout << minD.front() << "," << maxD.front() << " ";
                    if(v[j][i-k] == minD.front()) minD.pop_front();
                    addMin(v[j][i]);
                    if(v[j][i-k] == maxD.front()) maxD.pop_front();
                    addMax(v[j][i]);
                }
            }
            minMax[j][n-k] = {minD.front(), maxD.front()};
//            cout << minD.front() << "," << maxD.front() << "\n";
        }
        for (int i = 0; i <= n-k; i++) {
            minD.clear();
            maxD.clear();
            for (int j = 0; j < n; j++) {
                if(j < k) {
                    addMin(minMax[j][i].first);
                    addMax(minMax[j][i].second);
                } else {
                    sum += (maxD.front()-minD.front());
                    if (minMax[j-k][i].first == minD.front()) minD.pop_front();
                    addMin(minMax[j][i].first);
                    if (minMax[j-k][i].second == maxD.front()) maxD.pop_front();
                    addMax(minMax[j][i].second);
                }
            }
            sum += (maxD.front()-minD.front());
        }
        cout << sum << "\n";
    }
}
