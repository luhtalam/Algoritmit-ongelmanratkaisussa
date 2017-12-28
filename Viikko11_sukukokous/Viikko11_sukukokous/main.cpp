//#include <iostream>
//#include <cstring>
//#include <vector>
//
//using namespace std;
//
//int v[5002][5002];
//int r[5002][5002];
//int k[5002];
//
//int flow(int s, int n) {
//    k[s] = 1;
//    if(s == n)return 1;
//    for (int u = 0; u <= 5001;u++) {
//        if(!k[u] && r[s][u] > 0) {
//            if(flow(u,n)){
//                r[s][u] -= 1;
//                r[u][s] += 1;
//                return 1;
//            }
//        }
//    }
//    return 0;
//}
//
//void init(int t, int n) {
//    memcpy(r,v,sizeof(v));
//    for(int i = n; i < (t+1)*50; i+=50) r[i][5001]=1e9;
//}
//
//int main() {
//    cin.sync_with_stdio(0);
//    int n,m,p,a,b;
//    cin >> n >> m >> p;
//    for (int i = 1; i < 5000; i+=50) v[0][i]=1e9;
//    for (int i = 0; i < m; i++) {
//        cin >> a >> b;
//        if(a > b) swap(a,b);
//        b+= 50;
//        while(b < 5000) {
//            v[a][b] = v[b][a]= 1;
//            b+=50;
//            a+=50;
//        }
//    }
//    for(int i = 1; i < 100; i++) {
//        init(i,n);
//        a = 0;
//        while(flow(0,5001)) {
//            a++;
//            for(int i = 0; i <= 5001; i++) k[i] = 0;
//        }
//        if(a >= p) {
//            cout << i << endl;
//            break;
//        }
//        for(int i = 0; i <= 5001; i++) k[i] = 0;
//    }
//    return 0;
//}
#include <iostream>
#include <vector>

using namespace std;


int v[5001][5001];
vector<int> vl[5001];
int k[5001];

int flow(int s, int n) {
    k[s] = 1;
    if(s == n)return 1;
    for (auto u: vl[s]) {
        if(!k[u] && v[s][u] > 0) {
            if(flow(u,n)){
                v[s][u] -= 1;
                v[u][s] += 1;
                return 1;
            }
        }
    }
    return 0;
}

void init(int t) {
    for(int i = 1; i<=t*50; i++) {
        for(auto u: vl[i]) {
            v[i][u] = v[u][i] = 1;
        }
    }
    for(auto u: vl[0]) {
        if(u > t*50) continue;
        v[0][u] = 1e9;
        v[u][0] = 0;
    }
    for(auto u: vl[5000]) {
        if(u > t*50) continue;
        v[u][5000] = 1e9;
        v[5000][u] = 0;
    }
}

int main() {
    cin.sync_with_stdio(0);
    int n,m,p,a,b;
    cin >> n >> m >> p;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        for (int i = 0; i < 5000; i+=50) {
            vl[a+i].push_back(b+i+50);
            vl[b+i+50].push_back(a+i);
        }
        
    }
    for (int i = 0; i < 5000; i+=50) {
        vl[0].push_back(1+i);
        vl[1+i].push_back(0);
        vl[n+i].push_back(5000);
        vl[5000].push_back(n+i);
    }
    for (int i = 2; i < 100; i++) {
        init(i);
        a=0;
        while(flow(0,5000)) {
            a++;
            for(int i = 0; i <= 5000; i++) k[i] = 0;
        }
        if(a >= p) {
            cout << i-1 << endl;
            break;
        }
        for(int i = 0; i <= 5000; i++) k[i] = 0;
    }
    return 0;
}
