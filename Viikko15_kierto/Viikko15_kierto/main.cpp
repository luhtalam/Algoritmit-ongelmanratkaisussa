#include <iostream>

using namespace std;

long A = 911382323;
long B = 972663749;
long p[1000000];

int main() {
    string a,b;
    cin >> a >> b;
    p[0] = 1;
    for (int i = 1; i < b.length(); i++) {
        p[i] = p[i-1]*A;
        p[i] %= B;
    }
    long hashB;
    
    return 0;
}
