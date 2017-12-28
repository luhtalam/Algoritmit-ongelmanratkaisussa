#include <iostream>
#include <math.h>

using namespace std;

#define N (1<<18)
int p[2*N][3];


void eteenpain(int k) {
    if(p[k][2]) { //vie muutosta eteenpäin
        p[k][0] = p[k][2];
        if(k < N) {
            p[2*k][2] = p[k][2];
            p[2*k][1] = 0;
            p[2*k+1][2] = p[k][2];
            p[2*k+1][1] = 0;
        }
        p[k][2] = 0;
    }
    if(p[k][1]) { //vie summaa alaspäin
        p[k][0] += p[k][1];
        if(k < N) {
            p[2*k][1] += p[k][1];
            p[2*k+1][1] +=  p[k][1];
        }
        p[k][1] = 0;
    }
}

int lisaa(int a, int b, int k,int c, int x, int y) {
    if (b < x || a > y) {
        if(p[k][2]) return p[k][2] + p[k][1];
        return p[k][0]+p[k][1];
    }
    if (a <= x && b >= y){
        p[k][1] += c;
        if(p[k][2]) return p[k][2]+p[k][1];
        return p[k][0] + p[k][1];
    }
    eteenpain(k);
    int d = (y-x+1)/2;
    p[k][0] = min(lisaa(a,b,2*k,c,x, x+d-1),lisaa(a,b,2*k+1,c,x+d,y));
    return p[k][0];
}

int muuta(int a, int b, int k,int c, int x, int y) {
    if (b < x || a > y)  {
        if(p[k][2]) return p[k][2] + p[k][1];
        return p[k][0]+p[k][1];
    }
    if (a <= x && b >= y){
        p[k][2] = c;
        p[k][1] = 0;
        return p[k][2];
    }
    eteenpain(k);
    int d = (y-x+1)/2;
    p[k][0] = min(muuta(a,b,2*k,c,x, x+d-1),muuta(a,b,2*k+1,c,x+d,y));
    return p[k][0];
}

int minimi(int a, int b, int k, int x, int y) {
    if (b < x || a > y) return 1e9;
    if (a <= x && b >= y){
        if(p[k][2]) {
            p[k][0] = p[k][2];
            if(k < N) {
                p[2*k][2] = p[k][2];
                p[2*k][1] = 0;
                p[2*k+1][2] = p[k][2];
                p[2*k+1][1] = 0;
            }
            p[k][2] = 0;
        }
        p[k][0] += p[k][1];
        if(k < N) {
            p[2*k][1] += p[k][1];
            p[2*k+1][1] +=  p[k][1];
        }
        p[k][1] = 0;
        return p[k][0];
    }
    eteenpain(k);
    int d = (y-x+1)/2;
    return min(minimi(a,b,2*k,x, x+d-1),minimi(a,b,2*k+1,x+d,y));
}

int main() {
    cin.sync_with_stdio(0);
    int n,q,t,l,r,v;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> p[i+N][0];
    }
    for (int i = N-1; i>0; i--) {
        p[i][0] = min(p[2*i][0],p[2*i+1][0]);
    }
    for (int i = 0; i < q; i++) {
        cin >> t >> l >> r;
        if(t == 1) {
            cin >> v;
            muuta(l-1,r-1,1,v,0,N-1);
        } else if(t == 2) {
            cin >> v;
            lisaa(l-1,r-1,1,v,0,N-1);
        } else {
            cout << minimi(l-1,r-1,1,0,N-1) << "\n";
        }
    }
}
