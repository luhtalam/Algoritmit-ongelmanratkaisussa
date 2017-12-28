#include <iostream>
#include <math.h>

using namespace std;

long syt(long a, long b) {
    if(b == 0) return a;
    return syt(b, a%b);
}

int main() {
    cin.sync_with_stdio(0);
    long x1,x2,y1,y2 ;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << syt(abs(y2-y1),abs(x2-x1))+1 << endl;
    return 0;
}
