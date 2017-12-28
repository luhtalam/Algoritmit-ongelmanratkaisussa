#include <iostream>

using namespace std;

int main() { //vastaus noudattaa fibonaccin kaavaa. N:s luku on kahden edellisen summa. Kommentissa alla dynaaminen ratkaisu.
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    if(n == 1) {
        cout << "2\n";
        return 0;
    }
    if(n == 2) {
        cout << "4\n";
        return 0;
    }
    const int M = 1000000007;
    int a = 2;
    int b = 4;
    int c=0;
    for (int i = 2; i<n; i++) {
        c = a+b;
        c %= M;
        a =b;
        b=c;
    }
    cout << c << "\n";
    //    vector<pair<long,long>> one(n);
    //    vector<pair<long,long>> two(n);
    //    one[0] = {1,1};
    //    two[0] = {0,0};
    //    for (int i = 1; i <n; i++) {
    //        one[i].first = one[i-1].second + two[i-1].second;
    //        one[i].first %= M;
    //        two[i].first = one[i-1].first;
    //        two[i].first %= M;
    //        one[i].second = one[i-1].first + two[i-1].first;
    //        one[i].second %= M;
    //        two[i].second = one[i-1].second;
    //        two[i].second %= M;
    //    }
    //    n--;
    //    long total = one[n].first + one[n].second + two[n].first + two[n].second;
    //    total %= m;
    //    cout << total << "\n";
}
