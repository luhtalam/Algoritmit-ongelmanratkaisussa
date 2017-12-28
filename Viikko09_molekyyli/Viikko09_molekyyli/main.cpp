#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> v1[30001];
vector<int> v2[30001];

string haku(int s, int e, vector<int>* vk) {
    string temp = "0";
    vector<string> v;
    for(auto u: vk[s]) {
        if(u == e) continue;
        v.push_back(haku(u,s,vk));
    }
    sort(v.begin(),v.end());
    for(auto r: v) temp += r;
    temp += "1";
    return temp;
}

int main() {
    cin.sync_with_stdio(0);
    int n,a,b;
    cin >> n;
    for (int i = 1; i <n ; i++) {
        cin >> a >> b;
        v1[a].push_back(b);
        v1[b].push_back(a);
    }
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        v2[a].push_back(b);
        v2[b].push_back(a);
    }
    string s1 = haku(1,0,v1);
    string s2 = haku(1,0,v2);
    if(s1.compare(s2) == 0) cout << "YAY\n";
    else cout <<"QAQ\n";
    return 0;
}
