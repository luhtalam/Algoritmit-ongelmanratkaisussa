#include <iostream>

using namespace std;

int ta[27];
int tb[27];

int main() {
    cin.sync_with_stdio(0);
    string A,B;
    cin >> A >> B;
    int a = A.length();
    int b = B.length();
    int j=0, c= 0;
    for (int i =0; i < b; i++) {
        tb[B[i]-'a']++;
        while(j < a) {
            ta[A[j]-'a']++;
            if(A[j] == B[i]) {
                c++;j++;
                break;
            }
            j++;
        }
    }
    if(c == b) {
        cout << "maija\n";
        return 0;
    }
    for (int i = 0; i < 27; i++) {
        if(tb[i] > ta[i]) {
            cout << "QAQ\n";
            return 0;
        }
    }
    if(a > b) cout << "molemmat\n";
    else cout << "kaaleppi\n";
    return 0;
}
